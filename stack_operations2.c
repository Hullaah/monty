#include "monty.h"
/**
 * add - The opcode add adds the two top element of the stack,
 * pops the one at the top and stores the result as the top
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	size_t len = stack_length(*stack);
	int result;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		unload(NULL, *stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * nop - The opcode nop does nothing
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
}
/**
 * sub - The opcode sub subtacts the two top element of the stack,
 * pops the one at the top and stores the result as the top
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	size_t len = stack_length(*stack);
	int result;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		unload(NULL, *stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * mul - The opcode mul multiplies the two top element of the stack,
 * pops the one at the top and stores the result as the top
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_number)
{
	size_t len = stack_length(*stack);
	int result;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		unload(NULL, *stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * divide - The opcode divide divides the two top element of the
 * stack, pops the one at the top and stores the result as the top
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void divide(stack_t **stack, unsigned int line_number)
{
	size_t len = stack_length(*stack);
	int result;

	if (len < 2 || !((*stack)->n))
	{
		fprintf(stderr, len < 2 ? "L%u: can't div, stack too short\n"
		: "L%u: division by zero\n", line_number);
		unload(NULL, *stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
