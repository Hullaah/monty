#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	first = (*stack)->next;
	second = first->next;
	if (empty(*stack) || second == *stack) {
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		monty->error = true;
		return;
	}
	if (first->n == 0) {
		fprintf(stderr, "L%u: division by zero\n", line_number);
		monty->error = true;
		return;
	}
	second->n %= first->n;
	first->prev->next = second;
	second->prev = first->prev;
	free(first);
}
