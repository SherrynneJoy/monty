#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>

data_t data;

/**
 * freedata - frees the data struct
 */
void freedata(void)
{
	freelist(data.head);
	free(data.lineptr);
	fclose(data.fp);
}
/**
 * get_data - used with the global variable
 * @fp: a file descriptor
 */
void get_data(FILE *fp)
{
	data.arg = NULL;
	data.fp = fp;
	data.lineptr = NULL;
	data.lifi = 1;
	data.head = NULL;
	data.num = 1;
}
/**
 * open_file - opens a file
 * @argc: argument count
 * @argv: argument vector
 * Return: file pointer
 */
FILE *open_file(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
/**
 * main - main file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 when successful
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	/*char *lineptr = NULL;*/
	size_t n = 300;
	ssize_t is_read = 0;
	FILE *fp;
	char *lines[2] = {NULL, NULL};

	fp = open_file(argc, argv);
	get_data(fp);
	is_read = getline(&data.lineptr, &n, fp);
	while (is_read != -1)
	{
		lines[0] = strtok(data.lineptr, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = f_opecodes(lines[0]);
			if (f == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", data.num, lines[0]);
				freedata();
				exit(EXIT_FAILURE);
			}
			data.arg = strtok(NULL, " \t\n");
			f(&data.head, data.num);
		}
		is_read = getline(&data.lineptr, &n, fp);
		data.num++;
	}
	freedata();
	return (0);
}
