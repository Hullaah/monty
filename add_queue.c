#include "monty.h"
/**
 * add_queue- appends a node to a queue
 * @head: list head
 * @n: node element
 * Return: modified list head
*/
stack_t *add_queue(stack_t **head, int n)
{
	stack_t *node, *ptr = *head;

	node = malloc(sizeof(stack_t));
	if (!node || !head)
		return (NULL);
	while (ptr && ptr->next)
		ptr = ptr->next;
	node->next = NULL;
	node->prev = ptr;
	node->n = n;
	if (ptr)
		ptr->next = node;
	else
		*head = node;
	return (*head);
}
