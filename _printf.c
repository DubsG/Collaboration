#include "main.h"
#include <unistd.h>

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Prints every printable characters
 * @format: parameter for character strings
 * Return: return Printed characters excluding null byte
 */
int _printf(const char *format, ...)
{
	int q;

	printed = 0, char_printed = 0;
	int flags, width, precision, size, buffer_index = 0;

	va_list argument;

	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(argument, format);

	for (q = 0; format && format[q] != '\0'; q++)
	{
		if (format[q] != '%')
		{
			buffer[buffer_index++] = format[q];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			char_printed++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &q);
			width = get_width(format, &q, argument);
			precision = get_precision(format, &q, argument);
			size = get_size(format, &q);
			++q;
			printed = handle_print(format, &q, argument, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			char_printed += printed;
		}
	}
	print_buffer(buffer, &buffer_index);

	va_end(argument);

	return (char_printed);
}

/**
 * print_buffer - Prints the buffer's content
 * @buffer: Array of chars
 * @buffer_index: Index at which next character is added
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
