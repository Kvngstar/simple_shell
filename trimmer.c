#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

/**
 * TrimInput - Trims leading and trailing whitespaces from the input string.
 * @text: The input string to be trimmed.
 *
 * Return: A pointer to the trimmed string, or NULL if the string consists
 *         entirely of whitespaces or if the string matches the "exit" command.
 */
char *TrimInput(char *text)
{
	char *exitText = "exit";

	while (*text == '\t')
	{
		text++;
	}
	if (isspace(*text))
	{
		return (NULL);
	}
	else if (strcmp(text, exitText) == 0)
	{
		exit(0);
	}
	else if (text[strlen(text) - 1] == '\n')
	{
		text[strlen(text) - 1] = '\0';
	}

	return (text);
}
