#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: a string that contains the format specifiers
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int i = 0; /* index for the format string */
    int count = 0; /* count of printed characters */
    va_list args; /* list of variable arguments */
    char *s; /* pointer to a string argument */
    int n; /* an integer argument */
    char c; /* a character argument */

    if (format == NULL) /* check if format is valid */
        return (-1);

    va_start(args, format); /* initialize the argument list */

    while (format[i] != '\0') /* loop through the format string */
    {
        if (format[i] == '%') /* check if there is a format specifier */
        {
            i++; /* move to the next character */
            switch (format[i]) /* handle different cases */
            {
                case 'c': /* print a character */
                    c = va_arg(args, int); /* get the character argument */
                    write(1, &c, 1); /* write to the standard output */
                    count++; /* increment the count */
                    break;
                case 's': /* print a string */
                    s = va_arg(args, char *); /* get the string argument */
                    if (s == NULL) /* check if the string is valid */
                        s = "(null)"; /* use a default value */
                    write(1, s, _strlen(s)); /* write to the standard output */
                    count += _strlen(s); /* increment the count by the string length */
                    break;
                case '%': /* print a percent sign */
                    write(1, "%", 1); /* write to the standard output */
                    count++; /* increment the count */
                    break;
                case 'd': case 'i': /* print an integer in decimal base */
                    n = va_arg(args, int); /* get the integer argument */
                    count += print_int(n); /* print the integer and increment the count */
                    break;
                case '\0': /* handle the case of null character after '%' */
                    return (-1); /* return an error code */
                default: /* handle the case of invalid specifier */
                    write(1, "%", 1); /* write '%' to the standard output */
                    write(1, &format[i], 1); /* write the invalid character */
                    count += 2; /* increment the count by 2 */
            }
        }
        else /* if there is no format specifier, just print the character */
        {
            write(1, &format[i], 1); /* write to the standard output */
            count++; /* increment the count */
        }
        i++; /* move to the next character in the format string */
    }

    va_end(args); /* clean up the argument list */

    return (count); /* return the number of printed characters */
}
