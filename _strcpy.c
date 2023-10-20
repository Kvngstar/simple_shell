#include "main.h"


/**
 * _strcpy - Copy a string from source to destination.
 *
 * This function copies the string from the source pointer to the destination
 * pointer. It allocates memory for the destination string and ensures that
 * it is null-terminated.
 *
 * @dest: A pointer to the destination string.
 * @src: The source string to be copied.
 */
void _strcpy(char **dest, char *src) {
    int a = 0;
    int b = 0;

    while (*(src + b) != '\0') {
        b++;
    };

    *dest = malloc(sizeof(char) * b);  // Include space for the null terminator
    if (*dest == NULL) {
        perror("Memory allocation failed\n");
        exit(1);
    }

    while (a < b) {
        (*dest)[a] = src[a];
        a++;
    }

    (*dest)[b] = '\0';
}