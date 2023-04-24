#include "main.h"

/**
 * print_octal - Prints an unsigned number in octal notation
 * @arguments: parameter for arguments
 * @buffer: parameter buffer to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width
 * @precision: parameter for Precision specier
 * @size: parameter for size specifier
 * Return: returns args to be printed
 */
int print_octal(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{

	int q = BUFF_SIZE - 2;
	unsigned long int num = va_arg(arguments, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[q--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[q--] = (num % 8) + '0';
		num = num / 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[q--] = '0';

	q++;

	return (write_unsgnd(0, q, buffer, flags, width, precision, size));
}
