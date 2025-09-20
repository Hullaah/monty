#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#define UNUSED(x) ((void)(x))
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s {
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s {
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_state - holds the state of the interpreter
 * @lines: array of lines from the bytecode file
 * @stack: flag to indicate stack (true) or queue (false) mode
 * @current_line: current line number being executed
 * Description: holds the state of the interpreter
 */
struct monty_state {
	char **lines;
	bool stack;
	unsigned int current_line;
};

extern struct monty_state *monty;

char **strtow(char *str, char delim);

void execute(struct monty_state *monty);

void freevec(char **vector);

void (*dispatch(char *s))(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number);

void pall(stack_t **stack, unsigned int line_number);

void pint(stack_t **stack, unsigned int line_number);

void pop(stack_t **stack, unsigned int line_number);

void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);

void sub(stack_t **stack, unsigned int line_number);

void mul(stack_t **stack, unsigned int line_number);

void divide(stack_t **stack, unsigned int line_number);

void mod(stack_t **stack, unsigned int line_number);

void pchar(stack_t **stack, unsigned int line_number);

void pstr(stack_t **stack, unsigned int line_number);

void rotl(stack_t **stack, unsigned int line_number);

void rotr(stack_t **stack, unsigned int line_number);

void queue(stack_t **stack, unsigned int line_number);

void stack(stack_t **stack, unsigned int line_number);

#endif
