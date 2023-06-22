#include "monty.h"
/**
 * check - checks if all the letters in a string is a digit
 * @s: string to be checked
 * Return: integer
 */
int check(char *s)
{
	return (s[0] == '\0' ? 1 : isdigit(s[0]) && check(s + 1));
}
/**
 * get - gets the first word before a commma in a string
 * @string: string which word is to be got from
 * @stack: stack in case an error occurs
 * Return: string
*/
char *get(char *string, stack_t *stack)
{
	int i = 0, j = 0, malloced = 20, prev_malloced, status = 0;
	char *ret = malloc(malloced), *ptr;

	handle_malloc(ret, stack, 1);
	while (string[j] != '\0')
	{
		if (i == malloced)
		{
			prev_malloced = malloced;
			malloced += 20;
			ptr = _realloc(ret, prev_malloced, malloced);
			if (!ptr)
			{
				free(ret);
				handle_malloc(ptr, stack, 1);
			}
			ret = ptr;
		}
		if (string[j] == ' ' && status)
			break;
		if (string[j] == ' ' && !status)
		{
			j++;
			continue;
		}
		ret[i] = string[j];
		status = 1;
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
