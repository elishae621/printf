#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
 * print_char - Print a character to stdout
 * @valist: va_list containing the character to print
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_char(va_list valist, int *sum, char *flag)
{
        *sum += _putchar(va_arg(valist, int));
}
