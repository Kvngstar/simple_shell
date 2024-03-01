#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Comment - Checks if a string contains a comment symbol '#' and handles comments.
 * @text: The string to check.
 *
 * Return:
 *   - 1 if a comment symbol '#' is found at the beginning of the string.
 *   - 2 if a comment symbol '#' is found preceded by a space, in which case it removes the comment.
 *   - 0 if no comment symbol '#' is found.
 */

int Comment(char *text)
{
	int i = 0;

	while (i < _strlen(text))
	{
	if (text[i] == '#')
	{
	if (i == 0)
	{
	return (1);
	}
	else if (text[i - 1] == ' ')
	{
	text[i] = '\0';
	return (2);
	}
	}
	i++;
	}
	return (0);
}