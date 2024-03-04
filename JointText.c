#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * JoinText - Concatenates an array of strings into a single string with spaces
 *            between each element.
 * @array: The array of strings to concatenate.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the concatenated string.
 */
char *JoinText(char **array, int size)
{
	char *result;
	int total_length = 0;
	int offset = 0;
	int i;
	int j;

	for (i = 0; i < size; i++)
	{
		total_length += strlen(array[i]);
	}
	total_length += size - 1;
	result = malloc(total_length + 1);

	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < size; j++)
	{
		strcpy(result + offset, array[j]);
		offset += strlen(array[j]);

		if (j < size - 1)
		{
			result[offset++] = ' ';
		}
	}

	result[total_length] = '\0';

	return (result);
}
