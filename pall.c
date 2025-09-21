#include "monty.h"
#include <stdio.h>

/**
 * pall - prints all the values on the stack, starting from the top
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void pall(stack_t **sentinel, unsigned int line_number)
{
	stack_t *s = *sentinel;

	UNUSED(line_number);
	for (s = s->next; s != *sentinel; s = s->next)
		printf("%d\n", s->n);
}
