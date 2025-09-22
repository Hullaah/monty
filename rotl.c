#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void rotl(stack_t **sentinel, unsigned int line_number)
{
	stack_t *first, *last;

	UNUSED(line_number);
	first = (*sentinel)->next;
	last = (*sentinel)->prev;

	(*sentinel)->next = first->next;
	first->next->prev = *sentinel;

	last->next = first;
	first->prev = last;
	first->next = *sentinel;
	(*sentinel)->prev = first;
}
