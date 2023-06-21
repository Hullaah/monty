#include "monty.h"
/**
 * push -  The opcode push pushes an element to the stack
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	unsigned int idx = line_number - 1;
	int i;
	char **vec;
	stack_t *ptr;

	vec = strtow(vector[idx], ' ');
	if (!vec[1] || !check(vec[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_vec(vec);
		unload(NULL, *stack);
		exit(EXIT_FAILURE);
	}
	i = atoi(vec[1]);
	ptr = add_stack(stack, i);
	handle_malloc(NULL, ptr, 2);
	free_vec(vec);
}
/**
 * pall - The opcode pall prints all the element in the stack
 * @stack: stack
 * @line_number: op_code line number
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	UNUSED(line_number);
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
