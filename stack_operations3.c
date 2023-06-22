#include "monty.h"
/**
 * mod - The opcode mod gets the modulus of the two top element of th
 * e stack, pops the one at the top and stores the result as the top
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void mod(stack_t **stack, unsigned int line_number)
{
	size_t len = stack_length(*stack);
	int result;

	if (len < 2 || !((*stack)->n))
	{
		fprintf(stderr, len < 2 ? "L%u: can't mod, stack too short\n"
		: "L%u: division by zero\n", line_number);
		unload(NULL, *stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
