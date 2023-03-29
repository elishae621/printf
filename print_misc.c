#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
 * print_unsigned_specifier - Print an unsigned integer to stdout
 * @valist: va_list containing the integer to print
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_unsigned_specifier(va_list valist, int *sum, char *flag)
{
        print_unsigned_number(va_arg(valist, unsigned int), sum);
}
