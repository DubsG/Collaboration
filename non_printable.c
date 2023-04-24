#include "main.h"
#include <unistd.h>

/**
 * print_non_printable - Prints ASCII codes in hexa_dec of non printable chars
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width
 * @precision: Parameter for precision specifier
 * @size: parameter for size specifier
 * Return: return args to be printed
 */
int print_non_printable(va_list arguments, char buffer[], int flags,
		int width, int precision, int size)
{
	int q = 0, offset = 0;
	char *str = va_arg(arguments, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[q] != '\0')
	{
		if (is_printable(str[q]))
			buffer[q + offset] = str[q];
		else
			offset += append_hexa_code(str[q], buffer, q + offset);

		q++;
	}

	buffer[q + offset] = '\0';

	return (write(1, buffer, q + offset));
}
