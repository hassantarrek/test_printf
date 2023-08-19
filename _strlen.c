#include "main.h"

/**
 * _strlen - a function that returns the length of a string
 * @s: a pointer to a string
 * Return: the length of the string
 */
int _strlen(char *s)
{
    int len = 0; /* initialize the length */

    while (s[len] != '\0') /* loop through each character until null byte */
    {
        len++; /* increment the length */
    }

    return (len); /* return the length */
}
