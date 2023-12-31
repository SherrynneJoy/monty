#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>

data_t data;
/**
 * freedata - frees the global variable data
 */
void freedata(void)
{
	freestack(data.head);
	free(data.lineptr);
	fclose(data.fp);
}
/**
 * getdata - used to initialize global variable data
 * @fp: file pointer;
 */
void getdata(FILE *fp)
{
	data.arg = NULL;
	data.fp = fp;
	data.lineptr = NULL;
	data.lifi = 1;
	data.head = NULL;
	data.num = 1;
}
/**
 * openfile - opens a file
 * @argc: argument count
 * @argv: argument vector
 * Return: fp
 */
FILE *openfile(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
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
	size_t n = 400;
	ssize_t rd = 0;
	FILE *fp;
	char *lines[2] = {NULL, NULL};

	fp = openfile(argc, argv);
	getdata(fp);
	rd = getline(&data.lineptr, &n, fp);
	while (rd != -1)
	{
		lines[0] = strtok(data.lineptr, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = f_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", data.num, lines[0]);
				freedata();
				exit(EXIT_FAILURE);
			}
			data.arg = strtok(NULL, " \t\n");
			f(&data.head, data.num);
		}
		rd = getline(&data.lineptr, &n, fp);
		data.num++;
	}
	freedata();
	return (0);
}
