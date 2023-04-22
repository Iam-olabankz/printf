#include "main.h"

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
             int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
                int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int length = 0, i;

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, str, length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, str, length);
		}
		return (width);
	}

	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
                  int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
