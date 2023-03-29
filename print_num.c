#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
 * print_decimal_specifier - Print an integer to stdout
 * @valist: va_list containing the integer to print
 * @sum: pointer to total number of bytes written
 * @flag: string containing the flags for the conversion
 */
void print_decimal_specifier(va_list valist, int *sum, char *flag)
{
        print_number(va_arg(valist, int), sum, flag);
}
/**
 * print_binary_specifier - Prints binary to stdout
 * @valist: unused
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_binary_specifier(va_list valist, int *sum, char *flag)
{
        print_binary(va_arg(valist, unsigned int), sum);
}

/**
 * print_octal_specifier - Prints octal to stdout
 * @valist: unused
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_octal_specifier(va_list valist, int *sum, char *flag)
{
        print_octal(va_arg(valist, unsigned int), sum, flag);
}

/**
 * print_hex_lowercase_specifier - Prints hex to stdout
 * @valist: unused
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_hex_lowercase_specifier(va_list valist, int *sum, char *flag)
{
        print_hex_smallcase(va_arg(valist, unsigned long), sum, flag);
}

/**
 * print_hex_uppercase_specifier - Prints hex to stdout
 * @valist: unused
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_hex_uppercase_specifier(va_list valist, int *sum, char *flag)
{
        print_hex_uppercase(va_arg(valist, unsigned long), sum, flag);
}

