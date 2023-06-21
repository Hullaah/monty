#include "monty.h"
/**
 * handle_preload_error - handles likely erros that can occur before
 * the implementation of the monty interpreter like invalid command-
 * line arguments
 * @argc: this is the command-line argumwnt count
 * @fp: this is the file stream that was or is to be opened
 * @flag: a flag denoting which error to handle
 * @file: name of file
 * Return: void
*/
void handle_preload_error(int argc, FILE *fp, int flag, char *file)
{
	if (argc != 2 && flag == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (fp == NULL && flag == 1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

}
/**
 * handle_malloc - handle memory allocations related error
 * @string: string
 * @stack: stack
 * @flag: a flag denoting which error to handle
 * Return: void
*/
void handle_malloc(char *string, stack_t *stack, int flag)
{
	if (flag == 0 && !vector)
	{
		fprintf(stderr, "Error: malloc failed\n");
		unload(string, stack);
		exit(EXIT_FAILURE);
	}
	if (flag == 1 && !string)
	{
		fprintf(stderr, "Error: malloc failed\n");
		unload(NULL, stack);
		exit(EXIT_FAILURE);
	}
	if (flag == 2 && !stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		unload(string, NULL);
		exit(EXIT_FAILURE);
	}
}
/**
 * unload - unloads allocated memory
 * @string: string
 * @stack: stack
 * Return: void
*/
void unload(char *string, stack_t *stack)
{
	if (vector)
		free_vec(vector);
	if (string)
		free(string);
	if (stack)
		free_stack(stack);
}
/**
 * free_vec - frees a vector
 * @vec: vector to be freed
 * Return: void
*/
void free_vec(char **vec)
{
	char **traverse;

	for (traverse = vec; *traverse; traverse++)
		free(*traverse);
	free(vec);
}
