#include "main.h"

/**
 * CheckIfCommandExists - Check if a command exists in the system's directories and execute it.
 *
 * @command: The name of the command to check and execute.
 * @storeInputs: An array of command names and arguments.
 * @argcount: The number of elements in storeInputs.
 *
 * Return: 0 if the command exists and was executed successfully, -1 if not found or an error occurred.
 */
int CheckIfCommandExists(char *command, char **storeInputs, int argcount)
{
    pid_t childProcess;
    char *newargs[argcount];
    
    int checkStatus = checkforBuiltIn(storeInputs, argcount);

    if (checkStatus == -1)
    {
        char const *delimiter = ":";
        char *token;
        char *fullpath;
        struct dirent *entry;

        _strcpy(&fullpath, getenv("PATH"));
        token = strtok(fullpath, delimiter);

        while (token)
        {
            token = strtok(NULL, delimiter);
            DIR *directory = opendir(token);

            if (directory == NULL)
            {
                free(fullpath);
                return -1;
            }
            while ((entry = readdir(directory)) != NULL)
            {
                if (_strcmp(entry->d_name, command) == 0 || access(command, X_OK) == 0)
                {
                    childProcess = fork();

                    if (childProcess == -1)
                    {
                        free(fullpath);
                        perror("fork");
                        return 1;
                    }

                    if (childProcess == 0)
                    {

                        int a = 0;
                        int b = 1;
                        char *newtoken4;
                        char *args[5];

                        if (access(command, X_OK) != 0)
                        {
                            _strcpy(&newtoken4, token);
                            *(newtoken4 + strlen(token)) = '/';

                            while (a < strlen(storeInputs[0]))
                            {
                                newtoken4[strlen(token) + b] = *(storeInputs[0] + a);
                                a++;
                                b++;
                            }
                            newtoken4[_strlen(token) + b] = '\0';

                            if (argcount > 1)
                            {
                                int b = 0;
                                for (int i = 1; i < argcount; i++)
                                {
                                    _strcpy(&newargs[b], storeInputs[i]);
                                    b++;
                                }
                            }
                            else if (argcount == 1)
                            {
                                *newargs = NULL;
                            }
                            args[0] = storeInputs[0];
                            args[1] = *newargs;
                            args[2] = NULL;
                        }
                        else
                        {
                            _strcpy(&newtoken4, command);
                            *newargs = NULL;

                            args[0] = command;
                            args[1] = NULL;
                        }

                        char *envp[] = {NULL};

                        if (execve(newtoken4, args, envp) == -1)
                        {
                            free(newtoken4);
                            free(*newargs);
                            perror("execve");
                            return 1;
                        }
                        free(newtoken4);
                        b = 0;
                        if (argcount > 1)
                        {
                            for (int i = 1; i < argcount; i++)
                            {
                                free(newargs[b]);
                                b++;
                            }
                        }
                    }
                    else
                    {
                        int status;

                        waitpid(childProcess, &status, 0);
                        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
                        {
                            perror("child process");
                        }
                        free(fullpath);
                        closedir(directory);
                        return 0;
                    }
                    free(fullpath);
                    closedir(directory);
                    return 0;
                }
            }
        }
        free(fullpath);
        return -1;
    }
    return 0;
}