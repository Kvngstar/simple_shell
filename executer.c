#include "shell.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * Executer - Executes a command.
 * @command: The command to execute.
 * @argv: The arguments for the command.
 * @count: The number of arguments.
 * @main_argv: The main argument vector.
 *
 * Return: 1 on success, 0 on failure.
 */
int Executer(char *command, char **argv, int count, char ***main_argv)
{
	char completePath[max_Pathlength];

	if (command[0] == '/')
	{
		return (ExecuterSlachCommand(command, argv, count, main_argv));
	} else if (SearchName2(command))
	{
		return (SearchFuncName2(command));
	} else if (SearchName(command))
	{
		return (SearchFuncName(command, argv));
	} else if (strcmp(command, "echo") == 0 && (*argv)[0] == '$')
	{
	char *arg = argv[0];
	char *removeDollar = arg + 1;
	char *value = getenv(removeDollar);

	if (value == NULL)
	{
	printf("\n");
	return (0);
	}
	else
	{
	printf("%s\n", value);
	}
	return (1);
	}
	else
	{
	struct dirent *entry;
	char *token;
	char *path = getenv("PATH");
	char *pathcopy;

	if (path == NULL)
	{
	fprintf(stderr, "PATH environment variable not found\n");
	return (0);
	}
	pathcopy = malloc(strlen(path) + 1);

	if (pathcopy == NULL)
	{
	perror("malloc");
	return (0);
	}

	strcpy(pathcopy, path);
	token = strtok(pathcopy, ":");

	while (token != NULL)
	{
	DIR *directory = opendir(token);

	if (directory != NULL)
	{
	while ((entry = readdir(directory)) != NULL)
	{
	if (strcmp(entry->d_name, command) == 0 && access(token, X_OK) == 0)
	{
	pid_t child_process = fork();

	if (child_process == -1)
	{
	perror("fork");
	free(pathcopy);
	return (0);
	}
	if (child_process == 0)
	{
	int arr_1_size;
	int i;
	char **varyArray;

	strcpy(completePath, token);
	if (completePath[strlen(completePath) - 1] != '/')
	{
	strcat(completePath, "/");
	};
	strcat(completePath, command);

	arr_1_size = count;
	varyArray = malloc(sizeof(char *) * (arr_1_size + 2));
	varyArray[0] = completePath;

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
	}
	else
	{
	int status;

	waitpid(child_process, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
	perror("child process");
	free(pathcopy);
	return (0);
	}
	closedir(directory);
	free(pathcopy);
	return (1);
	}
	}
	}
	}
	token = strtok(NULL, ":");
	}
	free(pathcopy);
	fprintf(stderr, "%s: %d: %s: not found\n", (*main_argv)[0], __LINE__, command);
	return (0);
	}
	return (1);
}