#include "monty.h"
/**
 * _stack - The opcode _stack specifies that the data structure should be
 * treated as a stack
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void _stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	life.stack = 1;
	life.queue = 0;
}
/**
 * queue - The opcode queue specifies that the data structure should be
 * treated as a queue
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	life.stack = 0;
	life.queue = 1;
}
