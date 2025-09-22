#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pop - removes the top element of the stack
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void pop(stack_t **sentinel, unsigned int line_number)
{
	if (empty(*sentinel)) {
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		monty->error = true;
		return;
	}
	stack_t *tmp = (*sentinel)->next;
	(*sentinel)->next = (*sentinel)->next->next;
	(*sentinel)->next->prev = (*sentinel);
	free(tmp);
}
