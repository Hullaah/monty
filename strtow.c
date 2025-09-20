#include "monty.h"
#include <stdlib.h>
#include <stdbool.h>

static char *getword(char *str, int start, int len)
{
	char *word = calloc(len + 1, sizeof(char));
	if (word == NULL)
		return (NULL);
	for (int i = 0; i < len; i++)
		word[i] = str[start + i];
	word[len] = '\0';
	return (word);
}

/**
 * shrink_vector - shrinks the vector to the actual size
 * @vector: the vector to shrink
 * @veclen: the actual size of the vector
 * Return: pointer to the shrunk vector or NULL on failure
 */
static char **shrink_vector(char **vector, int veclen)
{
	char **new_vec;
	new_vec = (char **)calloc(veclen, sizeof(char *));
	if (new_vec == NULL)
		return (NULL);
	for (int k = 0; k < veclen; k++)
		new_vec[k] = vector[k];
	free(vector);
	return new_vec;
}

/**
 * resize - resizes the vector
 * @vector: the vector to resize
 * @n: the new size
 * Return: pointer to the resized vector or NULL on failure
 */
static char **resize(char **vector, int n)
{
	char **new_vec;
	int i = 0;

	new_vec = calloc(n, sizeof(char *));
	if (new_vec == NULL)
		return (NULL);
	while (*vector) {
		new_vec[i++] = *vector;
		vector++;
	}
	return new_vec;
}

/**
 * strtow - splits a string into words
 * @string: the string to split
 * @delim: the delimiter
 * Return: pointer to an array of strings (words)
 * or NULL on failure
 */
char **strtow(char *string, char delim)
{
	char **vector, **tmp;
	char *word;
	int veclen = 0, stringlen = 0, i = 0, j = 0;
	int n;
	bool in_word = false;

	n = 2;
	vector = (char **)calloc(n, sizeof(char *));
	if (vector == NULL)
		return (NULL);
	while (string[i]) {
		if (string[i] != delim && !in_word) {
			j = i;
			stringlen++;
			in_word = true;
		} else if (string[i] == delim && in_word) {
			in_word = false;
			word = getword(string, j, stringlen);
			if (word == NULL) {
				freevec(vector);
				return (NULL);
			}
			stringlen = 0;
			if (veclen + 1 == n) {
				n *= 2;
				tmp = vector;
				vector = resize(vector, n);
				free(tmp);
				if (vector == NULL) {
					freevec(vector);
					return (NULL);
				}
			}
			vector[veclen++] = word;
			vector[veclen] = NULL;
		} else if (in_word) {
			stringlen++;
		}
		i++;
	}
	if (in_word) {
		word = getword(string, j, stringlen);
		if (word == NULL) {
			freevec(vector);
			return (NULL);
		}
		if (veclen + 1 == n) {
			n *= 2;
			tmp = vector;
			vector = resize(vector, n);
			free(tmp);
			if (vector == NULL) {
				freevec(vector);
				return (NULL);
			}
		}
		vector[veclen++] = word;
		vector[veclen] = NULL;
	}
	vector[veclen++] = NULL;
	return (n == veclen				      ? vector :
		(tmp = shrink_vector(vector, veclen)) == NULL ? NULL :
								tmp);
}
