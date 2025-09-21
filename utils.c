#include "monty.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * delete_comments - frees the comments in the tokens
 * @tokens: array of tokens
 */
static void delete_comments(char **tokens)
{
	while (*tokens) {
		free(*tokens);
		tokens++;
	}
}
/**
 * remove_comments - removes comments from the tokens
 * @tokens: array of tokens
 * Return: pointer to the array of tokens without comments
 */
char **remove_comments(char **tokens)
{
	int i;

	for (i = 0; tokens[i]; i++) {
		if (tokens[i][0] == '#') {
			delete_comments(&tokens[i]);
			tokens[i] = NULL;
			break;
		}
	}
	return tokens;
}

/**
 * freestack - frees a stack
 * @sentinel: pointer to the sentinel node of the stack
 */
void freestack(stack_t *sentinel)
{
	stack_t *current = sentinel->next;
	stack_t *next;

	while (current != sentinel) {
		next = current->next;
		free(current);
		current = next;
	}
	free(sentinel);
}

/**
 * freevec - frees a vector of strings
 * @vector: the vector to free
 */
void freevec(char **vector)
{
	for (char **traverser = vector; *traverser; traverser++)
		free(*traverser);
	free(vector);
}

/**
 * do_cleanup - cleans up allocated resources
 * @monty: pointer to the monty state structure
 * @lines: array of lines to free
 * @tokens: array of tokens to free
 * @s: pointer to the stack sentinel node
 * @flags: flags indicating which resources to free
 */
void do_cleanup(struct monty_state *monty, char **lines, char **tokens,
		stack_t *s, unsigned int flags)
{
	if (flags & CLEAN_STACK)
		freestack(s);
	if (flags & CLEAN_TOKENS)
		freevec(tokens);
	if (flags & CLEAN_LINES)
		freevec(lines);
	if (flags & CLEAN_MONTY)
		free(monty);
}

/**
 * empty - checks if the stack is empty
 * @s: pointer to the stack sentinel node
 * Return: true if the stack is empty, false otherwise
 */
bool empty(stack_t *s)
{
	return s->next == s;
}
