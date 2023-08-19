#include "main.h"

/**
 * print_int - a function that prints an integer in decimal base
 * @n: an integer to be printed
 * Return: the number of digits printed
 */
int print_int(int n)
{
    int digit; /* a single digit of the number */
    int divisor = 1; /* a divisor for getting each digit from left to right */
    int count = 0; /* count of printed digits */

    if (n < 0) /* handle negative numbers */
    {
        write(1, "-", 1); /* print a minus sign */
        count++; 
        n = -n; /* make n positive for easier calculation */ 
    }

    while (n / divisor > 9) 
        divisor *= 10; 

    while (divisor != 0) 
    {
        digit = n / divisor; 
        write(1, &digit + '0', 1);
        count++;
        n %= divisor;
        divisor /= 10;
    }

    return (count);
}
