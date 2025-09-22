#include "monty.h"
#include <stdio.h>
/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void pchar(stack_t **sentinel, unsigned int line_number)
{
	stack_t *first = (*sentinel)->next;
	if (empty(*sentinel)) {
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		monty->error = true;
		return;
	}
	if (first->n < 0 || first->n > 127) {
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		monty->error = true;
		return;
	}
	printf("%c\n", first->n);
}
