#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

/**
 * Tokenizer - Splits the command and argument and the rest
 * @text: the incoming text
 * @command: commanding bot
 * @textArray: the outgoing array of text
 * @count: acts as the counter
 * Return: void or nothing
 * Description: This splits the text into command and the arguments
 */
void Tokenizer(char *text, char **command, char ***textArray, int *count)
{
	char *delimiter = " ";
	char *duplicateText;
	char *token;
	int counter = CalStrLen(text);
	int i = 0;

	duplicateText = malloc(strlen(text) + 1);

	strcpy(duplicateText, text);
	token = strtok(duplicateText, delimiter);
	*command = malloc(strlen(token) + 1);

	strcpy(*command, token);
	(*command)[strlen(token) + 1] = '\0';
	counter--;

	*textArray = (char **)malloc(sizeof(char *) * counter);
	if (*textArray == NULL)
	{
		fprintf(stderr, "Memory Allocation failed\n");
	}
	while (token != NULL)
	{
		token = strtok(NULL, delimiter);

		if (token != NULL)
		{
			char *trimToken = token;

			while (*trimToken == ' ')
			{
				trimToken++;
			}
			(*textArray)[i] = malloc(strlen(trimToken) + 1);

			if ((*textArray)[i] == NULL)
			{
				fprintf(stderr, "Memory Allocation failed\n");
			}

			strcpy((*textArray)[i], trimToken);

			i++;
		}
	}
	*count = counter;
	free(duplicateText);
}
