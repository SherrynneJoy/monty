#include "monty.h"
/**
 * addnode - adds a node to a linked list
 * @head: ptr to head ptr
 * @n: data of node
 */
void addnode(stack_t **head, int n)
{
	stack_t *temp = *head, *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		perror("Memory Allocation");
	if (temp != NULL)
		temp->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
