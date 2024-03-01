#include "shell.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * ExecuterSlachCommand - Executes a command.
 * @command: The command to execute.
 * @argv: The arguments for the command.
 * @count: The number of arguments.
 * @main_argv: The main argument vector.
 *
 * Return: 1 on success, 0 on failure.
 */
int ExecuterSlachCommand(char *command, char **argv, int count, char ***main_argv)
{
	char *newpath = malloc(strlen(command) + 1);

	if (newpath == NULL)
	{
		perror("malloc");
		return (0);
	}
	strcpy(newpath, command);
	if (access(command, X_OK) == 0)
	{

		pid_t child_process = fork();

		if (child_process == -1)
		{
			free(newpath);
			perror("fork");
			return (0);
		}
		if (child_process == 0)
		{

			int arr_1_size = count;

			char **varyArray = malloc(sizeof(char *) * (arr_1_size + 2));
			int i;

			varyArray[0] = newpath;

			for (i = 1; i <= arr_1_size; i++)
			{
				varyArray[i] = argv[i - 1];
			}
			varyArray[(arr_1_size + 1)] = NULL;

			if (execve(varyArray[0], varyArray, NULL) == -1)
			{
				perror("execve");
			}

			free_string_array(varyArray, arr_1_size + 2);
		} else
		{
			int status;

			waitpid(child_process, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				perror("child process");
				free(newpath);
				return (0);
			}
			free(newpath);
			return (1);
		}
	}
	fprintf(stderr, "%s: %d: %s: not found\n", (*main_argv)[0], __LINE__, command);
	free(newpath);
	return (1);
}