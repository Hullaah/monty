#include "monty.h"
/**
 * lines_count - count the number of words in a string
 * @str: string
 * @delim: delimeter
 * Return: number of words in a string
*/
int lines_count(char *str, char delim)
{
	int i = 0;
	int words = 0;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] == delim)
			words++;
	}
	return ((str[i - 1] != delim) ? words + 1 : words);
}
/**
 *  lines_length - calculates the length of each word in a string
 * @str: string
 * @word: The word in the string whose len
 * gth is to be calculated.
 * @delim: delimeter
 * @total_words: total words
 * e.g: first word, second word, third word and so on
 * Return: length of word in a string
*/
int lines_length(char *str, int word, char delim, int total_words)
{
	int i = 0, j = 0, words = 0, len = (int) strlen(str);

	if (word == total_words)
	{
		while (str[len] != delim)
		{
			j++;
			if (len - 1 < 0)
				return (j);
			len--;
		}
		return (j);
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] == delim)
		{
			words++;
			if (word == words)
			{
				if (str[i] == delim && i >= 1 && str[i - 1] == delim)
					j++;
				else if (str[i] == delim && i < 1)
					j++;
				else if (str[i] == delim && str[i - 1] != delim)
				{
					i--;
					while (str[i] != delim)
					{
						i--;
						j++;
					if (i < 0)
						break;
					}
				}
				break;
			}
		}
	}
	return (j);
}
/**
 * get_lines - gets the word in a string
 * @str: string
 * @word: word to be gotten. e.g whether first word, second word or third word
 * @total_words: total words
 * and so on is to be gotten
 * @delim: delimeter
 * Return: gotten lines
*/
char *get_lines(char *str, int word, char delim, int total_words)
{
	int i = 0, words = 0, ret, len = (int) strlen(str) - 1;

	if (word == total_words)
	{
		while (str[len] != delim)
		{
			if (len - 1 < 0)
				return (&str[len]);
			len--;
		}
		return (&str[len + 1]);
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] == delim)
		{
			words++;
			if (word == words)
			{
			ret = (str[i] == delim && i >= 1 && str[i - 1] == delim)
			|| (str[i] == delim && i < 1) ? i : ret;
				if (str[i] == delim && i >= 1 && str[i - 1] == delim)
					break;
				else if (str[i] == delim && i < 1)
					break;
				else if (str[i] == delim && str[i - 1] != delim)
				{
					i--;
					while (str[i] != delim)
					{
						ret = i--;
					if (i < 0)
						break;
					}
					break;
				}
			}
		}
	}
	return (&str[ret]);
}
/**
 * convert_lines - converts the buffer read from a file to an array of string
 * @str: string
 * @delim: delimeter
 * Return: array of words
*/
char **convert_lines(char *str, char delim)
{
	int total_word = lines_count(str, delim);
	int i, j, k, string_length;
	char **string_arr;
	char *tmp;

	if (str == NULL)
		return (NULL);
	string_arr = malloc((total_word + 1) * sizeof(char *));
	if (string_arr == NULL)
		return (NULL);
	for (i = 0; i < total_word; i++)
	{
		string_arr[i] = malloc(lines_length(str, i + 1, delim, total_word) + 1);
		if (string_arr[i] == NULL)
		{
			free(string_arr);
			return (NULL);
		}
	}
	for (k = 0; k < total_word; k++)
	{
		string_length = lines_length(str, k + 1, delim, total_word);
		for (j = 0; j < string_length; j++)
		{
			tmp = get_lines(str, k + 1, delim, total_word);
			if (string_length == 1 && tmp[j] == delim)
			{
				string_arr[k][0] = delim;
				string_arr[k][1] = '\0';
				break;
			}
			if (tmp[j] != delim)
				string_arr[k][j] = tmp[j];
		}
		if (!(string_length == 1 && tmp[0] == delim))
			string_arr[k][j] = '\0';
	}
	string_arr[k] = NULL;
	return (string_arr);
}
