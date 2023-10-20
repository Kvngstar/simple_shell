#include "main.h"
#include <stdio.h>

/**
 * _strcmp - Compare two strings.
 *
 * This function compares two strings, `s1` and `s2`, character by character.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 *
 * @return 0 if the strings are equal, a positive value if s1 is greater, and a
 * negative value if s2 is greater.
 */
int _strcmp(char *s1, char *s2)
{
    int a = 0;
    int b = 0;
    int c = 0;

    // Determine the length of s1
    while (*(s1 + a) != '\0')
    {
        a++;
    }

    // Determine the length of s2
    while (*(s2 + b) != '\0')
    {
        b++;
    }

    if (a > b)
    {
        while (c < a)
        {
            if (s1[c] == s2[c])
            {
                if (s1[c] == '\0' && s2[c] == '\0')
                {
                    return 0;
                }
                c++;
            }
            else if (s1[c] > s2[c])
            {
                c++;
                return 1;
            }
            else
            {
                c++;
                return -1;
            }
        }
    }
    else
    {
        while (c < b)
        {
            if (s1[c] == s2[c])
            {
                if (s1[c] == '\0' && s2[c] == '\0')
                {
                    return 0;
                }
                c++;
            }
            else if (s1[c] > s2[c])
            {
                c++;
                return 1;
            }
            else
            {
                c++;
                return -1;
            }
        }
    }
}