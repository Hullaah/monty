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
/**
 * pchar - The opcode pchar prints the char at the top of the stack, followed
 * by a new line.
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		unload(NULL, *stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		unload(NULL, *stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * pstr - The opcode pstr prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	UNUSED(line_number);
	while (ptr != NULL)
	{
		if (!(ptr->n > 0 && ptr->n < 127))
			break;
		putchar(ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}
/**
 * rotl - The opcode rotl rotates the stack to the top.
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack, *tmp;
	size_t len = stack_length(*stack);

	UNUSED(line_number);
	if (len > 1)
	{
		tmp = (*stack)->next;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = *stack;
		(*stack)->next = NULL;
		(*stack)->prev = ptr;
		*stack = tmp;
	}
}
/**
 * rotr - The opcode rotr rotates the stack to the bottom.
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack, *last;
	size_t len = stack_length(*stack);

	UNUSED(line_number);
	if (len > 1)
	{
		if (len == 2)
		{
			rotl(stack, line_number);
			return;
		}
		while (ptr->next->next)
			ptr = ptr->next;
		last = ptr->next;
		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		ptr->next = NULL;
		*stack = last;
	}
}
