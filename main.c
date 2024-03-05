#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry point for the program
 * @argc: The number of arguments passed to the program
 * @argv: An array containing the arguments passed to the program
 *
 * Return: Always returns 0
 *
 * Description: The main function of the shell program. It reads input
 * from the user or from a file and executes commands accordingly.
 */
int main(int argc, char **argv)
{
	if (isatty(fileno(stdin)))
	{
		if (argc < 2)
		{
			while (1)
			{
				char **textArray;
				char *command;
				int count;
				char *text = GetLineInput();

				SemiColon(text);
				SeparateInstruction(text, &command, &textArray, &count, &argv, argc);
			}
		} else
		{
			char **textArray;
			char *command;
			int count;

			char *text = JoinText(argv, argc);
			char *newText = TrimInput(text);
			char *token = strtok(newText, " ");
			char *newBuffer;

			if (token != NULL)
			{
				token = strtok(NULL, "");
			}
			newBuffer = TrimInput(token);
			SeparateInstruction(newBuffer, &command, &textArray, &count, &argv, argc);

			free(text);
		}
	} else
	{
		char buffer[1024];
		while (fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			char **textArray;
			char *command;
			int count;
			char *newBuffer;

			newBuffer = TrimInput(buffer);

			SeparateInstruction(newBuffer, &command, &textArray, &count, &argv, argc);
		}
	}
	return (0);
}

