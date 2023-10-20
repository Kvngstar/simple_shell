#include "main.h"

/**
 * getLineInput - Gets the input from the terminal or a string
 * @text: A pointer to a string to display as a prompt. Pass NULL to read from the terminal.
 *
 * Return: A pointer to the input string. The caller is responsible for freeing the memory.
 */

char *getLineInput(char *text)
{
    char *inputText = NULL;
    char *exitText = "exit";
    size_t size = 0;

    if (text == NULL)
    {
        printf("\n$ ");
        size_t outputNum = getline(&inputText, &size, stdin);
        if (outputNum == -1)
        {
            free(inputText);
            exit(0);
        }

        if (outputNum > 0 && inputText[outputNum - 1] == '\n')
        {
            inputText[outputNum - 1] = '\0';
        }
        if (strlen(inputText) == 0 || inputText == '\0' || inputText == '\n')
        {
            free(inputText);
            return NULL;
        }
        if (_strcmp(inputText, exitText) == 0)
        {
            free(inputText);
            exit(0);
        }
    }
    else
    {

        inputText = malloc(sizeof(char) * (strlen(text) + 1));
        if (inputText == NULL)
        {
            free(text);
            perror("malloc");
            exit(1);
        }
        _strcpy(&inputText, text);
        inputText[strlen(text)] = '\0';
        free(text);
    }
    return inputText;
}