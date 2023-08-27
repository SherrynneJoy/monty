#ifndef MONTY_H
#define MONTY_H

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
 * Description: a structure used with stacks and queues
   */
typedef struct bus_s
{
	char *arg;
	FILE *fp;
	char *lineptr;
	int lifi;
	unsigned int num;
	stack_t *head;
} data_t;
extern data_t data;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int fprintf(FILE *stream, const char *format, ...);
stack_t *addnode_end(stack_t **head, int n);
stack_t *addnode(stack_t **head, int n);
void freelist(stack_t *head);
void freedata(void);
void get_data(FILE *fp);
FILE *open_file(int argc, char *argv[]);
int main(int argc, char *argv[]);
void f_push(stack_t **head, unsigned int line_number);
void f_pall(stack_t **head, unsigned int line_number);
void f_pint(stack_t **head, unsigned int line_number);
void (*f_opecodes(char *opcode))(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **head, unsigned int line_number);
void f_nop(stack_t **head, unsigned int line_number);
void f_add(stack_t **head, unsigned int line_number);
void f_pop(stack_t **head, unsigned int line_number);
void f_sub(stack_t **head, unsigned int line_number);
void f_mul(stack_t **head, unsigned int line_number);
void f_div(stack_t **head, unsigned int line_number);
void f_mod(stack_t **head, unsigned int line_number);
#endif
