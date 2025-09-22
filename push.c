#include "monty.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * valid - checks if a string is a valid integer
 * @arg: the string to check
 * Return: true if valid, false otherwise
 */
static bool valid(char *arg)
{
	if (!arg)
		return false;
	while (*arg && isdigit(*arg++))
		;
	return !*arg;
}

/**
 * push - pushes an element to the stack
 * @sentinel: pointer to the sentinel node of the stack
 * @line_number: current line number (1-indexed)
 */
void push(stack_t **sentinel, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));
	if (node == NULL) {
		monty->error = true;
		return;
	}
	char **tmp = strtow(monty->lines[line_number - 1], ' ');
	if (tmp == NULL) {
		fprintf(stderr, "Error: malloc failed\n");
		free(node);
		monty->error = true;
		return;
	}
	char **tokens = remove_comments(tmp);
	if (!valid(tokens[1])) {
		freevec(tokens);
		free(node);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		monty->error = true;
		return;
	}
	node->n = atoi(tokens[1]);
	freevec(tokens);
	if (monty->stack) {
		node->next = (*sentinel)->next;
		node->prev = *sentinel;
		(*sentinel)->next->prev = node;
		(*sentinel)->next = node;
	} else {
		node->next = *sentinel;
		node->prev = (*sentinel)->prev;
		(*sentinel)->prev->next = node;
		(*sentinel)->prev = node;
	}
}
