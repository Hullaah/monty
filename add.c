#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add - adds the top two elements of the stack
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void add(stack_t **sentinel, unsigned int line_number)
{
	stack_t *first, *second;

	first = (*sentinel)->next;
	second = first->next;
	if (empty(*sentinel) || second == *sentinel) {
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		monty->error = true;
		return;
	}
	second->n += first->n;
	first->prev->next = second;
	second->prev = first->prev;
	free(first);
}
