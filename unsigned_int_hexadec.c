#include "main.h"

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width
 * @precision: parameter precision specifier
 * @size: parameter for size specifier
 * Return: return character printed
 */
int print_hexadecimal(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(arguments, "0123456789abcdef", buffer, flags, 'x',
				width, precision, size));
}
