#include "monty.h"

/**
 * addnode_end - adds a node at the end of a list
 * @head: a pointer to a pointer
 * @n: an integer
 * Return: node at the end
 */
stack_t *addnode_end(stack_t **head, int n)
{
	stack_t *new, *temp;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
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
	temp = *head;
	while (temp->next)
		temp = temp->next;
	new->next = temp->next;
	new->prev = temp;
	temp->next = new;
	return (temp->next);
}
/**
 * addnode - adds a node to a linked list
 * @head: ptr to head ptr
 * @n: data of node
 * Return: new node
 */
stack_t *addnode(stack_t **head, int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
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
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}
