#include "main.h"

/**
 * print_char - Prints sigle character
 * @arguments: parameter for lists of argument
 * @buffer: parameter for buffer array to handle print
 * @flags: parameter for calculated active flags
 * @width: parameter for breadth size
 * @precision: parameter for precision specification
 * @size: parameter for specifying size
 * Return: return chararacter printed
 */
int print_char(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	char c;

	c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
