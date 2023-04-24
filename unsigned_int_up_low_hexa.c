#include "main.h"

/**
 * print_hexa - Prints a hexadecimal number in upper or lower
 * @arguments: parameter for arguments
 * @mapping: parametr for array of values to map the number to
 * @buffer: parameter for buffer to handle printed args
 * @flags: parameter for calculated flags
 * @flag_ch: Calculates active flags
 * @width: parameter for width
 * @precision: parameter for Precision specifier
 * @size: paraameter for size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list arguments, char mapping[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(arguments, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[q--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[q--] = mapping[numb % 16];
		numb = numb / 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[q--] = flag_ch;
		buffer[q--] = '0';
	}

	q++;

	return (write_unsgnd(0, q, buffer, flags, width, precision, size));
}
