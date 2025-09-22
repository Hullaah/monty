#include "monty.h"
#include <stdio.h>

/**
 * swap - swaps the top two elements of the stack
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void swap(stack_t **sentinel, unsigned int line_number)
{
	stack_t *first, *second;

	first = (*sentinel)->next;
	second = first->next;
	if (empty(*sentinel) || second == *sentinel) {
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		monty->error = true;
		return;
	}
	first->prev->next = second;
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
}
