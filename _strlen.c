#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int lengthOfString = 0;

	while (*s != '\0')
	{
		lengthOfString++;
		s++;
	}

	return (lengthOfString);
}