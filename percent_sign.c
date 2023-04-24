#include "main.h"
#include <unistd.h>

/**
 * print_percent - Prints a percentage sign
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer to handle what to be printed
 * @flags: parameter for calculated active flags
 * @width: parameter for width.
 * @precision: parameter for precision specifier
 * @size: parameter for size specifier
 * Return: parameter for what to be printed
 */
int print_percent(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	UNUSED(arguments);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
