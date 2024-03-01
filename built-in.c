#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * set_env - Sets an environment variable.
 * @text: The input string containing the variable name and value.
 *
 * Return: 1 on success, 0 on failure.
 */
int set_env(char *text)
{
	 char *delim = "=";
	char *name = strtok(text, delim);
	char *value = strtok(NULL, delim);

	if (name != NULL && value != NULL)
	{
	if (setenv(name, value, 1) == -1)
	{
	perror("setenv");
	}
	else
	{
	return (1);
	}
	}
	else
	{
	printf("Invalid command format. Use: setenv VARIABLE_NAME=VALUE\n");
	}
	return (0);
}

/**
 * get_env - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: 1 on success, 0 on failure.
 */
int get_env(char *name)
{
	char *value = getenv(name);

	if (value != NULL)
	{
	printf("%s=%s\n", name, value);
	return (1);
	}
	return (0);
}

/**
 * unset_env - Unsets an environment variable.
 * @name: The name of the environment variable to unset.
 *
 * Return: 1 on success, 0 on failure.
 */
int unset_env(char *name)
{
	if (unsetenv(name) == -1)
	{
	perror("unsetenv");
	return (0);
	}
	return (1);
}

/**
 * cd - Changes the current directory.
 * @text: The directory to change to.
 *
 * Return: 1 on success, 0 on failure.
 */
int cd(char *text)
{
	if (text == NULL)
	{
	text = getenv("HOME");
	}
if (chdir(text) == 0)
{
	return (1);
	}
	else
	{
	perror("chdir");
	}
	return (0);
}

struct built_in functionArray[4] = {
	{"cd", cd}, {"export", set_env}, {"getenv", get_env}, {"unset", unset_env}
};

/**
 * SearchFuncName - Searches for a built-in function by name and executes it.
 * @command: The name of the command.
 * @arg: The argument for the command.
 *
 * Return: The result of the executed command.
 */
int SearchFuncName(char *command, char **arg)
{
	int i;

	for (i = 0; i < 4; i++)
	{
	if (strcmp(command, functionArray[i].funcName) == 0)
	{
	return (functionArray[i].function_pointer(*arg));
	}
	}
	return (2);
}

/**
 * SearchName - Searches for a built-in function by name.
 * @command: The name of the command.
 *
 * Return: 1 if the function is found, 0 otherwise.
 */
int SearchName(char *command)
{
	int i;

	for (i = 0; i < 4; i++)
	{
	if (strcmp(command, functionArray[i].funcName) == 0)
	{
	return (1);
	}
	}
	return (0);
}