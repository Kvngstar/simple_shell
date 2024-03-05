#include "shell.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * GetLineInput - Reads a line of input from stdin.
 *
 * Return: A pointer to the input line.
 */
char *GetLineInput(void)
{
	char *lineInputU;
	char *exitText = "exit\n";
	size_t size = 0;
	int textCount = 0;
	char *lineInput;

	printf("$ ");
	textCount = getline(&lineInputU, &size, stdin);
	lineInput = lineInputU;

	while (*lineInput == ' ')
	{
		lineInput++;
	}
	if (textCount == EOF)
	{
		free(lineInput);
		printf("\n");
		exit(0);
	} else if (textCount == 0 || isspace(*lineInput))
	{
		return (NULL);
	} else if (strcmp(lineInput, exitText) == 0)
	{
		free(lineInput);
		exit(0);
	} else if (textCount > 0 && lineInput[textCount - 1] == '\n')
	{
		lineInput[textCount - 1] = '\0';
	}
	return (lineInput);
}
