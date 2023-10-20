#include "main.h"

/**
 * cd - Change the current working directory.
 * @path: An array of strings where the first element is the directory path to change to.
 * @c: The number of elements in the path array.
 */
void cd(char **path, int c)
{
    if (chdir(path[1]) == 0)
    {
        printf("Changed directory to %s\n", path[1]);
    }
    else
    {
        perror("chdir");
    }
}

/**
 * pwd - Print the current working directory.
 * @text: Unused.
 * @c: Unused.
 */
void pwd(char **text, int c)
{
    char *buf;
    size_t size;

    size = pathconf(".", _PC_PATH_MAX);
    if ((buf = (char *)malloc((size_t)size)) != NULL)
    {
        if (getcwd(buf, (size_t)size) != NULL)
        {
            printf("%s\n", buf);
        }
        else
        {
            perror("getcwd");
        }
        free(buf);
    }
    else
    {
        perror("malloc");
    }
}

/**
 * echo - Print text to the standard output.
 * @text: An array of strings where the first element may contain arguments.
 * @c: The number of elements in the text array.
 */
void echo(char **text, int c)
{
    int count = 0;
    int i = 0;

    if (*(text[1]) == '-')
    {
        while (*(text[1] + i) != '\0')
        {
            i++;
        }
        count = 2;
        while (count < c)
        {
            if (count == (c - 1))
            {
                printf("%s  ", text[count]);
                break;
            }
            else
            {
                printf("%s ", text[count]);
            }
            count++;
        }
    }
    else
    {
        count = 1;
        while (count < c)
        {
            if (count == (c - 1))
            {
                printf("%s", text[count]);
                break;
            }
            else
            {
                printf("%s ", text[count]);
            }
            count++;
        }
    }
}

/**
 * clear - Clear the terminal screen.
 * @text: Unused.
 * @c: Unused.
 */
void clear(char **text, int c)
{
    printf("\033[H\033[J");
}

struct create_builtIn functionArray[4] = {
    {"cd", cd}, {"echo", echo}, {"pwd", pwd}, {"clear", clear}};

/**
 * checkforBuiltIn - Check if a command is a built-in function and execute it.
 * @text: An array of strings representing the command and its arguments.
 * @argcount: The number of elements in the text array.
 *
 * Return: int if the command is a built-in function and was executed successfully, -1 if not found.
 */
int checkforBuiltIn(char **text, int argcount)
{
    for (int i = 0; i < 4; i++)
    {
        if (_strcmp(text[0], functionArray[i].name) == 0)
        {
            functionArray[i].functionName(text, argcount);
            return 0;
        }
    }
    return -1;
}
