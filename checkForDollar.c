#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * Dollar - Checks if a string contains a dollar sign.
 * @text: The string to check.
 *
 * Return: 1 if a dollar sign is found, 0 otherwise.
 */
int Dollar(char *text)
{
	int i = 0;

	while (i < _strlen(text))
	{
	if (text[i] == '$')
	{
	return (1);
	}
	i++;
	}
	return (0);
}