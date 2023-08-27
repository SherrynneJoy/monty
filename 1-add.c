#include "monty.h"
/**
 * addnode - adds a node to a linked list
 * @head: ptr to head ptr
 * @n: data of node
 * Return: address of new ptr
 */
stack_t *addnode(stack_t **head, int n)
{
	stack_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freedata();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	(*head)->prev = new;
	new->next = (*head);
	new->prev = NULL;
	(*head) = new;
	return (*head);
}
/**
 * addnodeend - adds node at end
 * @head: head ptr
 * @n: data
 * Return: address of ptr
 */
stack_t *addnodeend(stack_t **head, int n)
{
	stack_t *new, *temp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freedata();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = (*head);
		new->prev = NULL;
		(*head) = new;
		return (*head);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	new->next = temp->next;
	new->prev = temp;
	temp->next = new;
	return (temp->next);
}
