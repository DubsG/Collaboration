#include "main.h"

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width
 * @precision: parameter for Precision specifier
 * @size: parameter for size specifier
 * Return: return character printed
 */
int print_hexa_upper(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(arguments, "0123456789ABCDEF", buffer, flags, 'X',
				width, precision, size));
}
