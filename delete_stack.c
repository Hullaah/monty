#include "monty.h"
/**
 * stack_length - calculates the length of a linked list
 * @h: head of linked list
 * Return: length of linked list
*/
size_t stack_length(stack_t *h)
{
	stack_t *ptr = h;
	size_t i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
/**
 * delete_stack_beg - deletes the node at the beginning of a linked list
 * @head: pointer to head of linked list
 * Return: 1
*/
void delete_stack_beg(stack_t **head)
{
	stack_t *tmp;

	if (*head)
	{
		tmp = (*head)->next;
		if (tmp)
			tmp->prev = NULL;
		free(*head);
		(*head) = tmp;
	}
}
/**
 * delete_stack_end - deletes the node at the end of a linked list
 * @head: pointer to head of linked list
 * Return: 1
*/
void delete_stack_end(stack_t **head)
{
	stack_t *ptr = *head;

	if (!ptr)
		return;
	while (ptr->next)
		ptr = ptr->next;
	if (ptr->prev)
		ptr->prev->next = NULL;
	free(ptr);
}
/**
 * delete_stack_at_index - deletes the node specified by index
 * from a linked list
 * @head: pointer to head of linked list
 * @index: index of node to be deleted
 * Return: 1 on Success -1 on failure
*/
void delete_stack_at_index(stack_t **head, unsigned int index)
{
	size_t list_len = stack_length(*head), i = 0;
	stack_t *ptr = *head;

	if (index >= list_len)
		return;
	if (index == 0)
		delete_stack_beg(head);
	else if (index == list_len - 1)
		delete_stack_end(head);
	else
	{
		while (i != index)
		{
			ptr = ptr->next;
			i++;
		}
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free(ptr);
	}
}
