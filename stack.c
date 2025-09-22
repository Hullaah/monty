#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the stack
 * @line_number: current line number (1-indexed)
 */
void stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	monty->stack = true;
}
