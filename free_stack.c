#include "monty.h"
/**
 * free_stack - fress a doubly linked list
 * @head: linked list head
 * Return: void (does not have a return value)
*/
void free_stack(stack_t *head)
{
	while (head)
		delete_stack_beg(&head);
}
