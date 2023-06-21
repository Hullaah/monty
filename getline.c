#include "monty.h"

/**
 * copy_to_buf - copies up to amount from param. from to param. to
 * @from: buffer to copy from
 * @to: buffer to copy to
 * @start: index to start copying from
 * @amount: amount of data to copy
 * Return: amount copied, 0 if NULL
*/

int copy_to_buf(char *from, char *to, int start, int amount)
{
	int i;

	if (!from || !to)
		return (0);
	for (i = 0; i < amount; i++)
	{
		to[start + i] = from[i];
	}
	return (i);
}

/**
 * _getline - A function similar to the standard library getline function
 * @lineptr: a pointer to the buffer that will hold the input line
 * @n: a pointer to the size of the buffer pointed to by lineptr
 * @fp: file stream
 * Description: the function dynamically allocates memory for a buffer to
 * hold the line of input read from the stream and automatically adjusts the
 * buffer size to fit the input line
 * Return: The function returns a signed integer value
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *fp)
{
	char c[1024], *new_lineptr;
	ssize_t num_read = 0;
	size_t i = 0, prev_malloced;

	if (*lineptr == NULL)
	{
		*n = 1024;
		*lineptr = malloc(*n);
		if (!*lineptr)
			fclose(fp);
		handle_malloc(*lineptr, NULL, 1);
	}
	while (1)
	{
		if (i >= *n - 1)
		{
			prev_malloced = *n;
			*n *= 2;
			new_lineptr = _realloc(*lineptr, prev_malloced, *n);
			if (new_lineptr == NULL)
			{
				free(*lineptr);
				fclose(fp);
				handle_malloc(new_lineptr, NULL, 1);
			}
			*lineptr = new_lineptr;
		}
		num_read = fread(&c, 1, 1024, fp);
		if (num_read == 0)
			break;
		i += copy_to_buf(c, *lineptr, i, num_read);
		if ((*lineptr)[i - 1] == '\n')
			break;
	}
	if (!num_read)
		(*lineptr)[i] = '\0';
	else
		(*lineptr)[i - 1] = '\0';
	return (i);
}
