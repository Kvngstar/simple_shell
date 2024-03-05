#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

/**
 * SeparateInstruction - Splits the input text into commands and arguments.
 * @text: The input text to be parsed.
 * @command: Pointer to store the command.
 * @textArray: Pointer to store the array of text.
 * @count: Pointer to store the number of elements in the array.
 * @argv: Pointer to store additional arguments.
 * @argc: Number of arguments.
 *
 * This function parses the input text, separates commands and arguments, and store * them in the specified pointers for further processing.
 *
 * Return: Always returns 1.
 */
int SeparateInstruction(char *text, char **command, char ***textArray,
			int *count, char ***argv, int argc)
{
	char *delim = ";";
	char *token;
	char *saveptr1;

	char *duplicateText = malloc(strlen(text) + 1);

	strcpy(duplicateText, text);

	token = strtok_r(duplicateText, delim, &saveptr1);
	while (token != NULL)
	{

	int countand = countAnd(token);
	int countor = countOr(text);

	if (countand > 0)
	{
		And(token, argv);
		break;
	} else if (countor > 0)
	{
		Or(token, argv);
		break;
	} else
	{

		Tokenizer(token, command, textArray, count);
		Executer(*command, *textArray, *count, argv);

		free(*command);
		free_string_array(*textArray, *count);
	}

	token = strtok_r(NULL, delim, &saveptr1);
	}
	if (argc < 2 && isatty(fileno(stdin)))
	{
	free(text);
	}
	free(duplicateText);

	return (1);
}
