#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @arguments: parametr for arguments
 * @buffer: parameter for buffer to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width
 * @precision: parrameter for Precision specifier
 * @size: parameter for size specifier
 * Return: return character to be printed
 */
int print_pointer(va_list arguments, char buffer[], int flags,
		int width, int precision, int size)
{
	char added_char = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_address;
	char mapping[] = "0123456789abcdef";
	void *address = va_arg(arguments, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = mapping[num_address % 16];
		num_address = num_address / 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		added_char = '+', len++;
	else if (flags & F_SPACE)
		added_char = ' ', len++;

	ind++;

	return (write_pointer(buffer, ind, len, width, flags, padd,
				added_char, padd_start));
}
