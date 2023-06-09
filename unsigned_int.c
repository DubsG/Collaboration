#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer to handle printed arg
 * @flags: parameter for calculates flags
 * @width: parameter for width
 * @precision: parameter for Precision specifier
 * @size: parameter for size specifier
 * Return: returns argument to be printed
 */
int print_unsigned(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(arguments, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[q--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[q--] = (num % 10) + '0';
		num = num / 10;
	}
	q++;

	return (write_unsgnd(0, q, buffer, flags, width, precision, size));
}
