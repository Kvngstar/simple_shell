#ifndef MAIN_H
#define MAIN_H

#include "main.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

/**
 * struct create_builtIn - Represents a custom built-in command.
 * @name: The name of the built-in command.
 * @functionName: A function pointer to the associated function.
 * Description:
 * The `create_builtIn` structure is used to define custom built-in commands in a command-line interpreter.
 * It associates a name (command) with the corresponding function pointer that implements the command's functionality.
 */

struct create_builtIn
{
    char *name;
    void (*functionName)(char **c, int);
};

char *getLineInput(char *text);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
void Tokenize(char *input, char ***storeInputs, int *number);
int _strlen(char *s);
void _strcpy(char **dest, char *src);
int CheckIfCommandExists(char *command, char **args, int c);
void clear(char **text, int c);
char *getPath(void);
void cd(char **args, int c);
void echo(char **args, int c);
int checkforBuiltIn(char **text, int c);

#endif