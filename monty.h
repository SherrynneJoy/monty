#ifndef MONTY_H
#define MONTY_H

#define  _POSIX_C_SOURCE >= 200809L
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct bus_s - used with stacks & queues
 * @arg: argument
 * @fp: file pointer
 * @lineptr: ptr to line
 * @lifi: int
 * Description: used with stacks and queues
   */
typedef struct bus_s
{
	char *arg;
	FILE *fp;
	char *lineptr;
	int lifi;
} bus_t;
extern bus_t comm;

int execute(char *lineptr, stack_t **stack, unsigned int count, FILE *fp);
void freestack(stack_t *head);
void addnode(stack_t **head, int n);
void f_push(stack_t **head, unsigned int count);
void f_pall(stack_t **head, unsigned int count);

#endif