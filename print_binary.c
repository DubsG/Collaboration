#include "main.h"
#include <unistd.h>

/**
 * print_binary - convert unsigned integers to base two
 * @arguments: parametr for arguments
 * @buffer: parameter for buffer to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width.
 * @precision: parameter for precision specifier
 * @size: parameter for size specifier
 * Return: argument to be printed in base two
 */
int print_binary(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int n, q, y, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(arguments, unsigned int);
	q = 2147483648;
	a[0] = n / q;
	for (y = 1; y < 32; y++)
	{
		q = q / 2;
		a[y] = (n / q) % 2;
	}
	for (y = 0, sum = 0, count = 0; y < 32; y++)
	{
		sum += a[y];
		if (sum || y == 31)
		{
			char z = a[y] + '0';

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
