#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

void mul(stack_t **sentinel, unsigned int line_number)
{
	stack_t *first, *second;

	first = (*sentinel)->next;
	second = first->next;
	if (empty(*sentinel) || second == *sentinel) {
		printf("L%u: can't sub, stack too short\n", line_number);
		monty->error = true;
		return;
	}
	second->n *= first->n;
	first->prev->next = second;
	second->prev = first->prev;
	free(first);
}
