#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * countAnd - Counts the occurrences of the logical AND operator in a string.
 * @text: The string to count occurrences of the logical AND operator.
 *
 * Return: The number of occurrences of the logical AND operator.
 */
int countAnd(char *text)
{
	int i = 0;

	while (*text != '\0')
	{
	if (*text == '&' && *(text + 1) == '&')
	{
	i++;
	}
	text++;
	}
	return (i);
}

/**
 * StealText - Splits a string by the logical AND operator and stores the parts
 * @text: The string to split.
 * @count: The number of parts.
 * @arr: the argument
 */
void StealText(char *text, int count, char ***arr)
{
	int num = 0;
	char *token;

	*arr = malloc(sizeof(char *) * (count + 1));
	token = strtok(text, "&&");

	while (token != NULL)
	{

	char *trimToken = token;

	while (*trimToken == ' ')
	{
	trimToken++;
	}

	(*arr)[num] = malloc(strlen(trimToken) + 1);

	strcpy((*arr)[num], trimToken);
	num++;

	token = strtok(NULL, "&&");
	}
}

/**
 * And - Executes commands separated by the logical AND operator.
 * @text: The string containing commands separated by the logical AND operator.
 * @argv: The argument vector.
 */
void And(char *text, char ***argv)
{
	int count = countAnd(text);
	char *command;
	char **textArray;
	int increment = 0;
	int count2;
	char **arr;
	int num;

	StealText(text, count, &arr);
	while (arr[increment] != NULL)
	{
	Tokenizer(arr[increment], &command, &textArray, &count2);
	num = Executer(command, textArray, count2, argv);

	if (num == 0)
	{
	break;
	}
	increment++;
	}
	free(command);
	free_string_array(textArray, count2);
	free_string_array(arr, count);
}