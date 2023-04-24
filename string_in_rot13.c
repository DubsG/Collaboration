#include "main.h"

/**
 * print_rot13string - Prints string in rot13.
 * @arguments: parameter for arguments
 * @buffer: parameter for buffer to handle printed args
 * @flags: parameter for calculated flags
 * @width: parameter for width
 * @precision: parameter for Precision specifier
 * @size: parameter for size specifier
 * Return: return args to be printed
 */
int print_rot13string(va_list arguments, char buffer[], int flags, int width,
		int precision, int size)
{
	char x;
	char *string;
	unsigned int q, m;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arguments, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (q = 0; str[q]; q++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == str[q])
			{
				x = out[m];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[m])
		{
			x = str[q];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
