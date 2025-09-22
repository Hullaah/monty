#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

struct monty_state *monty;

/**
 * readContents - reads the contents of a file descriptor
 * @fd: file descriptor
 * Return: pointer to the contents or NULL on failure
 */
static char *readContents(int fd)
{
	char tmp[1024];
	char *contents;
	ssize_t size, n = 0;

	contents = NULL;
	while ((size = read(fd, tmp, sizeof(tmp))) > 0) {
		n += size;
		contents = realloc(contents, n + 1);
		if (contents == NULL) {
			fprintf(stderr, "Error: malloc failed\n");
			return NULL;
		}
		strncpy(contents + n - size, tmp, size);
	}
	contents[n] = '\0';
	if (size < 0) {
		fprintf(stderr, "Error: Can't read file\n");
		return NULL;
	}
	return contents;
}

/**
 * main - entry point
 * @argc: command-line argument count
 * @argv: command-line argument vector
 * Return: exit status
*/
int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "Error : Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	monty = malloc(sizeof(struct monty_state));
	if (monty == NULL) {
		fprintf(stderr, "Error: malloc failed\n");
		close(fd);
		return EXIT_FAILURE;
	}
	char *buffer = readContents(fd);
	close(fd);
	if (buffer == NULL) {
		free(monty);
		return EXIT_FAILURE;
	}
	monty->lines = strtow(buffer, '\n');
	monty->current_line = 1;
	monty->stack = true;
	monty->error = false;
	if (monty->lines == NULL) {
		free(buffer);
		free(monty);
		fprintf(stderr, "Error: malloc failed\n");
		return EXIT_FAILURE;
	}
	free(buffer);
	execute(monty);
	freevec(monty->lines);
	free(monty);
	return EXIT_SUCCESS;
}
