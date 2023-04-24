#include "main.h"
#include <unistd.h>

/**
 * print_string - Prints strings of character
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer array to handle strings
 * @flags:  parameter for calculated active flags
 * @width: parameter for width.
 * @precision: parameter for Precision specifier
 * @size: parameter for size specifier
 * Return: Return strings of character printed
 */
int print_string(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	int len = 0;
	int q;
	char *string = va_arg(arguments, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (string == NULL)
	{
		string = "(nil)";
		if (precision >= 6)
			string = "      ";
	}
	while (string[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], len);
			for (q = width - len; q > 0; q--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (q = width - len; q > 0; q--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (width);
		}
	}
	return (write(1, string, len));
}
