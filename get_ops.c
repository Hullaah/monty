#include "monty.h"
/**
 * get_ops - gets the command to be executed for an op_code
 * to be executed for the command
 * @s: command
 * Return: function to be executed for command or null
*/
void (*get_ops(char *s))(stack_t **stack, unsigned int line_number)
{
	int i, loop;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", divide},
		{"mod", mod},
		{NULL, NULL}
	};

	loop = (sizeof(op) / sizeof(op[0])) - 1;
	for (i = 0; i < loop; i++)
	{
		if (!_strcmp(op[i].opcode, s))
			return (op[i].f);
	}
	return (op[i].f);
}
