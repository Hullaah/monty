#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * sentinel - creates and initializes a sentinel node for the stack
 * Return: pointer to the sentinel node or NULL on failure
 */
inline static stack_t *sentinel(void)
{
	stack_t *s = malloc(sizeof(stack_t));
	if (s == NULL)
		return NULL;
	s->next = s;
	s->prev = s;
	return s;
}

/**
 * execute - executes the monty bytecode commands
 * @monty: monty state structure
*/
void execute(struct monty_state *monty)
{
	stack_t *s = sentinel();
	void (*func)(stack_t **stack, unsigned int line_number);

	if (s == NULL) {
		do_cleanup(monty, monty->lines, NULL, NULL,
			   CLEAN_MONTY | CLEAN_LINES);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (char **traverser = monty->lines; *traverser; traverser++) {
		char *line = monty->lines[monty->current_line - 1];
		char **tmp, **tokens;

		tmp = strtow(line, ' ');
		if (tmp == NULL) {
			do_cleanup(monty, monty->lines, NULL, s,
				   CLEAN_LINES | CLEAN_MONTY | CLEAN_STACK);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		tokens = remove_comments(tmp);
		if (tokens == NULL) {
			do_cleanup(monty, monty->lines, NULL, s,
				   CLEAN_LINES | CLEAN_MONTY | CLEAN_STACK);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		if (tokens[0] && strcmp(tokens[0], "")) {
			func = dispatch(tokens[0]);
			if (!func) {
				fprintf(stderr, "L%u: unknown instruction %s\n",
				       monty->current_line, tokens[0]);
				do_cleanup(monty, monty->lines, tokens, s,
					   CLEAN_ALL);
				exit(EXIT_FAILURE);
			}
			func(&s, monty->current_line);
			if (monty->error) {
				do_cleanup(monty, monty->lines, tokens, s,
					   CLEAN_ALL);
				exit(EXIT_FAILURE);
			}
		}
		freevec(tokens);
		monty->current_line++;
	}
	freestack(s);
}
