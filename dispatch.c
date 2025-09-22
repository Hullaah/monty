#include "monty.h"
#include <string.h>

/**
 * dispatch - dispatches to the command to be executed for an opcode
 * @s: command
 * Return: function to be executed for command or null
*/
void (*dispatch(char *s))(stack_t **stack, unsigned int line_number)
{
	int i, n;
	instruction_t instructions[] = {
		{ "push", push },   { "pall", pall },	{ "pint", pint },
		{ "swap", swap },   { "pop", pop },	{ "add", add },
		{ "nop", nop },	    { "sub", sub },	{ "mul", mul },
		{ "div", divide },  { "mod", mod },	{ "pchar", pchar },
		{ "pstr", pstr },   { "rotl", rotl },	{ "rotr", rotr },
		{ "stack", stack }, { "queue", queue },
	};

	n = (sizeof(instructions) / sizeof(instructions[0]));
	for (i = 0; i < n; i++) {
		if (!strcmp(instructions[i].opcode, s))
			return (instructions[i].f);
	}
	return (NULL);
}
