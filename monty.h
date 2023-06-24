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

/**
 * struct program - a structure for the program life
 * @life.vector: the buffer that'll store the input read from the file
 * @queue: an integer denoting whether the data structure is a queue
 * @stack: an integer denoting whether the data structure is a stack
 * Description: this structure stores what'd be needed throughout the life
 * cycle of the program
*/
typedef struct program
{
        char **vector;
        int stack;
        int queue;
} program;

extern program life;

ssize_t _getline(char **lineptr, size_t *n, FILE *fp);

char **strtow(char *str, char delim);

char **convert_buf(char *str);

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

stack_t *add_queue(stack_t **head, int n);

void delete_stack_beg(stack_t **head);

void print_stack(stack_t *h);

size_t stack_length(stack_t *h);

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

void _stack(stack_t **stack, unsigned int line_number);

#endif
