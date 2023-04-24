#include "main.h"
#include <unistd.h>

/**
 * print_reverse - Prints strings in reverse order
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width
 * @precision: parameter for Precision specifier
 * @size: parameter for size specifier
 * Return: return args to be printed
 */

int print_reverse(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	char *string;
	int q, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(arguments, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = "(Null)";
	}
	for (q = 0; str[q]; q++)
		;

	for (q = q - 1; q >= 0; q--)
	{
		char c = str[q];

		write(1, &c, 1);
		count++;
	}
	return (count);
}
