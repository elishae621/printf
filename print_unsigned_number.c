#include "main.h"

/**
 *print_unsigned_number - print_unsigned_number
 *@n: unsigned int
 *@sum: sum of bytes written
 */
void print_unsigned_number(unsigned int n, int *sum)
{
	unsigned int num = n;
	char tmp;

	if (num > 9)
	{

		print_unsigned_number(num / 10, sum);
	}

	tmp = num % 10 + '0';
	*sum += _putchar(tmp);
}
