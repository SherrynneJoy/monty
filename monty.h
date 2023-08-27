#ifndef MONTY_H
#define MONTY_H

/*#define  _POSIX_C_SOURCE >= 200809L*/
/*#define  _GNU_SOURCE*/

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
 * struct data_s - struct containing data used
 * @lineptr: gets a line
 * @arg: argument
 * @fp: file pointer
 * @head: head ptr
 * @num: line no
 * @lifi: checks whether a struct is a stack/queue
 */
typedef struct data_s
{
	char *lineptr;
	char *arg;
	FILE *fp;
	stack_t *head;
	unsigned int num;
	int lifi;
} data_t;
extern data_t data;
void freedata(void);
void getdata(FILE *fp);
FILE *openfile(int argc, char *argv[]);
void (*f_opcodes(char *opcode))(stack_t **stack, unsigned int line_no);
stack_t *addnodeend(stack_t **head, int n);
stack_t *addnode(stack_t **head, int n);
void f_push(stack_t **head, unsigned int line_no);
void f_pall(stack_t **head, unsigned int line_no);
void f_pop(stack_t **head, unsigned int line_no);
void f_pint(stack_t **head, unsigned int line_no);
void f_swap(stack_t **head, unsigned int line_no);
void f_add(stack_t **head, unsigned int line_no);
void f_nop(stack_t **head, unsigned int line_no);
void freestack(stack_t *head);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif
