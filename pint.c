#include "monty.h"
#include <stdio.h>

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void pint(stack_t **sentinel, unsigned int line_number)
{
	if (empty(*sentinel)) {
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		monty->error = true;
		return;
	}
	printf("%d\n", (*sentinel)->next->n);
}
