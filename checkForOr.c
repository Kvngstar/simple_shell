#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * countOr - Counts the occurrences of the logical OR operator in a string.
 * @text: The string to count occurrences of the logical OR operator.
 *
 * Return: The number of occurrences of the logical OR operator.
 */
int countOr(char *text)
{
	int i = 0;

	while (*text != '\0')
	{
		if (*text == '|' && *(text + 1) == '|')
		{
			i++;
		}
		text++;
	}
	return (i);
}

/**
 * StealText2 - Splits a string by the logical OR operator and stores the parts in an array.
 * @text: The string to split.
 * @count: The number of parts.
 * @arr2: the args
 */
void StealText2(char *text, int count, char ***arr2)
{
	int num = 0;
	char *token;

	*arr2 = malloc(sizeof(char *) * (count + 1));
	token = strtok(text, "||");

	while (token != NULL)
	{
		char *trimToken = token;

		while (*trimToken == ' ')
		{
			trimToken++;
		}

		(*arr2)[num] = malloc(strlen(trimToken) + 1);

		strcpy((*arr2)[num], trimToken);
		num++;
		token = strtok(NULL, "||");
	}
}

/**
 * Or - Executes commands separated by the logical OR operator.
 * @text: The string containing commands separated by the logical OR operator.
 * @argv: The argument vector.
 */
void Or(char *text, char ***argv)
{
	int count = countOr(text);
	char *command;
	char **textArray;
	int increment = 0;
	int num;
	int count2;
	char **arr2;

	StealText2(text, count, &arr2);
	while (arr2[increment] != NULL)
	{
		Tokenizer(arr2[increment], &command, &textArray, &count2);
		num = Executer(command, textArray, count2, argv);

		if (num == 1)
		{
			break;
		}
		increment++;
	}

	free(command);
	free_string_array(textArray, count2);
	free_string_array(arr2, count);
}