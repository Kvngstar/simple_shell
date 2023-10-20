#include"main.h"
/**
 * main - Entry point for a simple command-line interpreter.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, or an error code if something goes wrong.
 */
int main(int argc, char **argv)
{
char **storeInputs;
int arguCount;
int checkpipe = 0;

if (isatty(fileno(stdin)))
		checkpipe++;

if (argc < 2)
{
    while (1)
	{
        char *inputText = getLineInput(NULL);
            if (inputText != NULL)
			{
                Tokenize(inputText, &storeInputs, &arguCount);
                int exists = CheckIfCommandExists(storeInputs[0], storeInputs, arguCount);

                if (exists == -1)
				{
                    perror(storeInputs[0]);
                }
                int freespace = 0;

                while (freespace < arguCount)
				{
                    free(storeInputs[freespace]);
                    freespace++;
                }
                free(storeInputs);
                free(inputText);
              if(checkpipe == 0)
                	exit(0);
            }
            else
			{
                continue;
            }
        }
    }
	else if (argc > 1)
	{
        char *text;
        int a = 1;
        int b = 0;
        int counter = 0;

        while (a < argc)
		{
            counter = counter + strlen(*(argv + a));
            counter++;
            a++;
        }
        a = 1;
        text = malloc(sizeof(char) * (counter + 1));
        int i = 0;

        while (a < argc)
		{
            char *changetext = *(argv + a);
            while (b < strlen(changetext)) 
			{
                text[i] = *(changetext + b);
                i++;
                b++;
            }
            a++;

            if (a == argc)
			{
                text[i] = '\0';
                break;
            }

            b = 0;
            text[i] = ' ';
            i++;
        }
        Tokenize(text, &storeInputs, &arguCount);
        int exists = CheckIfCommandExists(storeInputs[0], storeInputs, arguCount);

        if (exists == -1)
		{
            perror(storeInputs[0]);
        }
        int freespace = 0;

        while (freespace < arguCount)
		{
            free(storeInputs[freespace]);
            freespace++;
        }
        free(storeInputs);
    }

    return (0);
}
