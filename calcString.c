#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * CalStrLen - Calculates the number of substrings in a string separated by a delimiter.
 * @text: The string to calculate the number of substrings.
 *
 * Return: The number of substrings.
 */
int CalStrLen(char *text)
{
	char *token;
	char *delim = " ";
	int counter = 0;
	char *duplicateText;

	duplicateText = malloc(strlen(text) + 1);

	strcpy(duplicateText, text);
	token = strtok(duplicateText, delim);

	while (token != NULL)
	{
	token = strtok(NULL, delim);
	counter++;
	}
	free(duplicateText);
	return (counter);
}