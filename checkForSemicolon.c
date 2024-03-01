#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * SemiColon - Checks if a string contains a semicolon.
 * @text: The string to check.
 *
 * Return: 1 if a semicolon is found, 0 otherwise.
 */
int SemiColon(char *text)
{
	int i = 0;

	while (i < _strlen(text))
	{
		if (text[i] == ';')
		{
			return (1);
		}
		i++;
	}
	return (0);
}