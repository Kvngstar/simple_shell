#include <stdlib.h>
#include "shell.h"

/**
 * free_string_array - Frees memory allocated for an array of strings.
 * @array: The array of strings to free.
 * @size: The size of the array.
 */
void free_string_array(char **array, int size)
{
	int i;

	if (array == NULL)
	{
		return;
	}
	for (i = 0; i < size; ++i)
	{
		if (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
		}
	}

	free(array);
}
