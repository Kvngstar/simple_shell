#include "main.h"

/**
 * Tokenize - Tokenize an input string into an array of strings.
 *
 * This function takes an input string and tokenizes it into individual
 * strings using a space delimiter. The resulting tokens are stored in
 * an array of strings.
 *
 * @param input The input string to tokenize.
 * @param storeInputs A pointer to an array to store the tokens.
 * @param argCount A pointer to an integer to store the number of tokens.
 */
void Tokenize(char *input, char ***storeInputs, int *argCount)
{
    char const *delimiter = " ";
    char *tokens;
    char *duplicateString;
    int a = 0;
    int b = 0;

    _strcpy(&duplicateString, input);
    tokens = strtok(duplicateString, delimiter);

    while (tokens != NULL)
    {
        a++;
        tokens = strtok(NULL, delimiter);
    }
    *argCount = a;

    *storeInputs = malloc(sizeof(char *) * a);
    if (*storeInputs == NULL)
    {
        free(*storeInputs);
        free(input);
        exit(0);
    }
    free(duplicateString);

    _strcpy(&duplicateString, input);
    tokens = strtok(duplicateString, delimiter);

    while (tokens != NULL)
    {
        _strcpy(&(*storeInputs)[b], tokens);
        tokens = strtok(NULL, delimiter);
        b++;
    }
    free(duplicateString);
}