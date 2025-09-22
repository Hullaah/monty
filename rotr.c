#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void rotr(stack_t **sentinel, unsigned int line_number)
{
	stack_t *first, *last;

	UNUSED(line_number);
	first = (*sentinel)->next;
	last = (*sentinel)->prev;

	(*sentinel)->prev = last->prev;
	last->prev->next = *sentinel;

	last->next = first;
	last->prev = *sentinel;
	first->prev = last;
	(*sentinel)->next = last;
}
