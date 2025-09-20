#include "monty.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * shrink_vector - shrinks the vector to the actual size
 * @vector: the vector to shrink
 * @veclen: the actual size of the vector
 * Return: pointer to the shrunk vector or NULL on failure
 */
static char **shrink_vector(char **vector, int veclen)
{
	char **tmp;
	tmp = (char **)calloc(veclen, sizeof(char *));
	if (tmp == NULL)
		return (NULL);
	for (int k = 0; k < veclen; k++)
		tmp[k] = vector[k];
	free(vector);
	return tmp;
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
		new_vec[i] = *vector;
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
	char **vector;
	int veclen = 0, strlen = 0, i = 0, j = 0;
	int n;
	bool in_word = false;

	n = 2;
	vector = (char **)calloc(n, sizeof(char *));
	if (vector == NULL)
		return (NULL);
	while (string[i]) {
		if (string[i] != delim && !in_word) {
			j = i;
			strlen++;
			in_word = true;
		} else if (string[i] == delim && in_word) {
			in_word = false;
			char *word = calloc(strlen, sizeof(char));
			if (word == NULL)
				return (NULL);
			for (int k = 0; k < strlen; k++)
				word[k] = string[j++];
			strlen = 0;
			if (veclen == n) {
				n *= 2;
				vector = resize(vector, n);
			}
			vector[veclen] = word;
			vector[++veclen] = NULL;
		} else if (in_word) {
			strlen++;
		}
		i++;
	}
	vector[veclen++] = NULL;
	return n == veclen ? vector : shrink_vector(vector, veclen);
}
