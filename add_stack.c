#include "monty.h"
/**
 * add_stack - prepends a node to a doubly linked list
 * @head: pointer to head of node
 * @n: node element
 * Return: head of modified list
*/
stack_t *add_stack(stack_t **head, int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node || !head)
		return (NULL);
	node->n = n;
	node->next = *head;
	node->prev = NULL;
	if (*head)
		(*head)->prev = node;
	*head = node;
	return (*head);
}
