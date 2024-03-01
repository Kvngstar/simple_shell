#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
/**
 * print_env - Print environment variables
 *
 * This function prints all the environment variables to the standard output.
 *
 * Return: 1 on success, 0 on failure
 */
int print_env(void)
{
	system("printenv");
	return (1);
}

/**
 * clear - Clear the terminal screen
 *
 * This function clears the terminal screen by sending appropriate control
 * characters.
 *
 * Return: 1 on success, 0 on failure
 */
int clear(void)
{
	printf("\033[H\033[J");
	return (1);
}

/**
 * pwd - Print the current working directory
 *
 * This function prints the current working directory to the standard output.
 *
 * Return: 1 on success, 0 on failure
 */
int pwd(void)
{
	size_t size;
	char *buf;

	size = pathconf(".", _PC_PATH_MAX);

	buf = (char *)malloc((size_t)size);

	if (buf != NULL)
	{
		if (getcwd(buf, (size_t)size) != NULL)
		{
			printf("%s\n", buf);
			free(buf);
			return (1);
		}
		else
		{
			perror("getcwd");
		}
	}
	else
	{
		perror("malloc");
	}
	free(buf);
	return (0);
}

/**
 * functionArray2 - Array of built-in functions
 */
struct built_in_2 functionArray2[4] = {
	{"printenv", print_env},
	{"clear", clear},
	{"pwd", pwd},
	{"env", print_env}
};

/**
 * SearchFuncName2 - Search for a built-in function by name
 * @command: The name of the command
 *
 * This function searches for a built-in function by name and executes it if
 * found.
 *
 * Return: The result of the function execution, or 0 if the function is not
 * found.
 */
int SearchFuncName2(char *command)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (strcmp(command, functionArray2[i].funcName) == 0)
		{
			return (functionArray2[i].function_pointer2());
		}
	}
	return (0);
}

/**
 * SearchName2 - Search for a built-in function name
 * @command: The name of the command
 *
 * This function searches for a built-in function name.
 *
 * Return: 1 if the function name is found, 0 otherwise
 */
int SearchName2(char *command)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (strcmp(command, functionArray2[i].funcName) == 0)
		{
			return (1);
		}
	}
	return (0);
}