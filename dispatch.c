#include "monty.h"
#include <string.h>

/**
 * dispatch - dispatches to the command to be executed for an opcode
 * @s: command
 * Return: function to be executed for command or null
*/
void (*dispatch(char *s))(stack_t **stack, unsigned int line_number)
{
	int i, loop;
	instruction_t op[] = {
		{ "push", push },   { "pall", pall },	{ "pint", pint },
		{ "swap", swap },   { "pop", pop },	{ "add", add },
		{ "nop", nop },	    { "sub", sub },	{ "mul", mul },
		{ "div", divide },  { "mod", mod },	{ "pchar", pchar },
		{ "pstr", pstr },   { "rotl", rotl },	{ "rotr", rotr },
		{ "stack", stack }, { "queue", queue }, { NULL, NULL }
	};

	loop = (sizeof(op) / sizeof(op[0])) - 1;
	for (i = 0; i < loop; i++) {
		if (!strcmp(op[i].opcode, s))
			return (op[i].f);
	}
	return (op[i].f);
}
