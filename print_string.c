#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
 * print_string - Print a string to stdout
 * @valist: va_list containing the string to print
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_string(va_list valist, int *sum, char *flag)
{
        *sum += _putstring(va_arg(valist, char *));
}

/**
 * print_S_specifier - Print a string to stdout, replacing non-printable
 * characters with their ASCII codes in hexadecimal notation
 * @valist: va_list containing the string to print
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_S_specifier(va_list valist, int *sum, char *flag)
{
        print_S(va_arg(valist, char *), sum);
}
