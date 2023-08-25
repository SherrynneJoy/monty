#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
bus_t drive  = {NULL, NULL, NULL, 0};
/**
 * main - main file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 when successful
 */
int main(int argc, char *argv[])
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t is_read = 1;
	FILE *fp;
	unsigned int count = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	drive.fp = fp;
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (is_read > 0)
	{
		is_read = getline(&lineptr, &n, fp);
		drive.lineptr = lineptr;
		count++;
		if (is_read > 0)
		{
			execute(lineptr, &stack, count, fp);
		}
		free(lineptr);
	}
	freestack(stack);
	fclose(fp);

	return (0);
}
