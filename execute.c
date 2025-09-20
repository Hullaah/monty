#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * execute - executes the monty bytecode commands
 * @monty: monty state structure
*/
void execute(struct monty_state *monty)
{
	stack_t *s = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);

	for (char **traverser = monty->lines; *traverser; traverser++) {
		char *line = monty->lines[monty->current_line - 1];
		char **tokens = strtow(line, ' ');
		if (tokens == NULL) {
			freevec(tokens);
			freevec(monty->lines);
			free(monty);
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		if (tokens[0] && strcmp(tokens[0], "")) {
			func = dispatch(tokens[0]);
			if (!func) {
				printf("L%u: unknown instruction %s\n",
				       monty->current_line, tokens[0]);
				freevec(tokens);
				freevec(monty->lines);
				free(monty);
				exit(EXIT_FAILURE);
			}
			func(&s, monty->current_line);
			monty->current_line++;
		}
		freevec(tokens);
	}
}
