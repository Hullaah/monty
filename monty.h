#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#define UNUSED(x) (((void) (x)))
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
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
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



extern char **vector;

ssize_t _getline(char **lineptr, size_t *n, FILE *fp);

char **strtow(char *str, char delim);

int _strcmp(char *s1, char *s2);

char *get(char *string, stack_t *stack);

void (*get_ops(char *s))(stack_t **stack, unsigned int line_number);

void handle_preload_error(int argc, FILE *fp, int flag, char *file);

void unload(char *string, stack_t *stack);

void handle_malloc(char *string, stack_t *stack, int flag);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void free_vec(char **vec);

void free_stack(stack_t *head);

int check(char *s);

stack_t *add_stack(stack_t **head, int n);

void print_stack(stack_t *h);

void push(stack_t **stack, unsigned int line_number);

void pall(stack_t **stack, unsigned int line_number);

void delete_stack_beg(stack_t **head);

#endif