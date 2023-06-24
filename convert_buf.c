#include "monty.h"
/**
 * lines_count - count the number of lines in the read buffer
 * @buf: buffer
 * Return: number of lines in a buffer
*/
int lines_count(char *buf)
{
	int i = 0;
	int lines = 0;

	for (; buf[i] != '\0'; i++)
	{
		if (buf[i] == '\n')
			lines++;
	}
	return ((buf[i - 1] != '\n') ? lines + 1 : lines);
}
/**
 * lines_length - calculates the length of each line in the read buffer
 * @buf: buffer
 * @line: The line in the buffer whose length is to be calculated.
 * @total_lines: total lines
 * e.g: first line, second line, third line and so on
 * Return: length of line in a buffer
*/
int lines_length(char *buf, int line, int total_lines)
{
	int i = 0, j = 0, lines = 0, len = (int) strlen(buf) - 1;

	if (line == total_lines && buf[len] != '\n')
	{
		while (buf[len] != '\n')
		{
			j++;
			if (len - 1 < 0)
				return (j);
			len--;
		}
		return (j);
	}
	for (; buf[i] != '\0'; i++)
	{
		if (buf[i] == '\n')
		{
			lines++;
			if (line == lines)
			{
				if (buf[i] == '\n' && i >= 1 && buf[i - 1] == '\n')
					j++;
				else if (buf[i] == '\n' && i < 1)
					j++;
				else if (buf[i] == '\n' && buf[i - 1] != '\n')
				{
					i--;
					while (buf[i] != '\n')
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
 * get_lines - gets the line in a buffer
 * @buf: buffer
 * @line: line to be gotten. e.g whether first line, second line or third line
 * @total_lines: total lines
 * and so on is to be gotten
 * @'\n': '\n'eter
 * Return: gotten lines
*/
char *get_lines(char *buf, int line, int total_lines)
{
	int i = 0, lines = 0, ret, len = (int) strlen(buf) - 1;

	if (line == total_lines && buf[len] != '\n')
	{
		while (buf[len] != '\n')
		{
			if (len - 1 < 0)
				return (&buf[len]);
			len--;
		}
		return (&buf[len + 1]);
	}
	for (; buf[i] != '\0'; i++)
	{
		if (buf[i] == '\n')
		{
			lines++;
			if (line == lines)
			{
			ret = (buf[i] == '\n' && i >= 1 && buf[i - 1] == '\n')
			|| (buf[i] == '\n' && i < 1) ? i : ret;
				if (buf[i] == '\n' && i >= 1 && buf[i - 1] == '\n')
					break;
				else if (buf[i] == '\n' && i < 1)
					break;
				else if (buf[i] == '\n' && buf[i - 1] != '\n')
				{
					i--;
					while (buf[i] != '\n')
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
	return (&buf[ret]);
}
/**
 * convert_buf - converts the buffer read from a file to an array of line
 * @buf: buffer
 * Return: array of lines
*/
char **convert_buf(char *buf)
{
	int total_line = lines_count(buf);
	int i, j, k, line_length;
	char **line_arr;
	char *tmp;

	if (buf == NULL)
		return (NULL);
	line_arr = malloc((total_line + 1) * sizeof(char *));
	if (line_arr == NULL)
		return (NULL);
	for (i = 0; i < total_line; i++)
	{
		line_arr[i] = malloc(lines_length(buf, i + 1, total_line) + 1);
		if (line_arr[i] == NULL)
		{
			free(line_arr);
			return (NULL);
		}
	}
	for (k = 0; k < total_line; k++)
	{
		line_length = lines_length(buf, k + 1, total_line);
		for (j = 0; j < line_length; j++)
		{
			tmp = get_lines(buf, k + 1, total_line);
			if (line_length == 1 && tmp[j] == '\n')
			{
				line_arr[k][0] = '\n';
				line_arr[k][1] = '\0';
				break;
			}
			if (tmp[j] != '\n')
				line_arr[k][j] = tmp[j];
		}
		if (!(line_length == 1 && tmp[0] == '\n'))
			line_arr[k][j] = '\0';
	}
	line_arr[k] = NULL;
	return (line_arr);
}
