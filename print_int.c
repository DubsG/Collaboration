#include "main.h"

/**
 * print_int - Prints integer
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer array to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width.
 * @precision: parameter for precision specifier
 * @size: parameter for size specifier
 * Return: return args printed
 */
int print_int(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	int q = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(arguments, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[q--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[q--] = (num % 10) + '0';
		num = num / 10;
	}

	q++;

	return (write_number(is_negative, q, buffer, flags, width, precision, size));
}
