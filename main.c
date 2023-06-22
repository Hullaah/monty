#include "monty.h"
char **vector;
/**
 * main - entry point
 * @argc: command-line argument count
 * @argv: command-line argument vector
 * Return: exit status
*/
int main(int argc, char *argv[])
{
	char *lineptr = NULL, *gotten;
	size_t n = 0;
	FILE *fp;
	unsigned int i;
	stack_t *stack = NULL;
	void (*op)(stack_t **, unsigned int);

	handle_preload_error(argc, NULL, 0, NULL);
	fp = fopen(argv[1], "r");
	handle_preload_error(0, fp, 1, argv[1]);
	_getline(&lineptr, &n, fp);
	fclose(fp);
	vector = strtow(lineptr, '\n');
	free(lineptr);
	handle_malloc(NULL, stack, 0);
	for (i = 0; vector[i]; i++)
	{
		gotten = get(vector[i], stack);
		if (gotten[0] == '\0' || gotten[0] == '#' || vector[i][0] == '#')
		{
			free(gotten);
			continue;
		}
		op = get_ops(gotten);
		if (!op)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", i + 1, gotten);
			unload(gotten, stack);
			exit(EXIT_FAILURE);
		}
		free(gotten);
		op(&stack, i + 1);
	}
	unload(NULL, stack);
	exit(EXIT_SUCCESS);
}
