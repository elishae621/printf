#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * print_percent_specifier - Print a percent sign to stdout
 * @valist: unused
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_percent_specifier(va_list valist, int *sum, char *flag)
{
	*sum += _putchar('%');
}

/**
 * print_rot13_specifier - Prints rot13 to stdout
 * @valist: unused
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_rot13_specifier(va_list valist, int *sum, char *flag)
{
	print_rot13(va_arg(valist, char *), sum);
}

/**
 * print_reverse_string_specifier - Prints reversed string to stdout
 * @valist: unused
 * @sum: pointer to total number of bytes written
 * @flag: unused
 */
void print_reverse_string_specifier(va_list valist, int *sum, char *flag)
{
	print_reverse_string(va_arg(valist, char *), sum);
}

/**
 * _exec_specifier - run specifer
 * @s: specifer
 * @valist: valist
 * @sum: total number of bytes written
 * @flag: flag
 * Return: no of bytes written
 */
typedef void (*specifier_func_t)(va_list, int *, char *);
void _exec_specifier(char s, va_list valist, int *sum, char *flag)
{
	static const specifier_func_t specifier_functions[] = {
		['c'] = print_char,
		['s'] = print_string,
		['S'] = print_S_specifier,
		['d'] = print_decimal_specifier,
		['i'] = print_decimal_specifier,
		['u'] = print_unsigned_specifier,
		['%'] = print_percent_specifier,
		['b'] = print_binary_specifier,
		['o'] = print_octal_specifier,
		['x'] = print_hex_lowercase_specifier,
		['X'] = print_hex_uppercase_specifier,
		['R'] = print_rot13_specifier,
		['r'] = print_reverse_string_specifier
	};
	specifier_func_t func = specifier_functions[(int)s];

	if (func)
	{
		func(valist, sum, flag);
	}
}
/**
 * _printf - prints a string
 * @format: printing format
 * Return: no of bytes written
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int *sum, no_of_flags = 0;
	char *flags, specifier;
	char *flag;

	flags = malloc(sizeof(char) * 6);
	flag = malloc(sizeof(char) * 6);

	flags = "-+ #0";

	sum = malloc(sizeof(int));
	*sum = 0;

	va_start(valist, format);

	while (format != NULL && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			/* %[flags][width][.precision][length]specifier */
			if (_found_in(flags, *format))
			{
				*(flag + no_of_flags++) = *format;
				format++;
				specifier = *format;
			}
			specifier = *format;
			_exec_specifier(specifier, valist, sum, flag);
		}
		else
		{
			*sum += _putchar(*format);
		}
		format++;
	}
	return (*sum);
}
