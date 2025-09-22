#include "monty.h"
#include <stdio.h>
/**
 * pstr - prints the string starting at the top of the stack, followed by a new line
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void pstr(stack_t **sentinel, unsigned int line_number)
{
	stack_t *ptr = (*sentinel)->next;

	UNUSED(line_number);
	while (ptr && ptr->n != 0 && ptr->n > 0 && ptr->n <= 127) {
		putchar(ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}
