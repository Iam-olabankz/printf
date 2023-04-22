#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_s - prints a string
 * @s: the string to print
 *
 * Return: the number of characters printed
 */
int print_s(char *s)
{
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}

/**
 * _putchar - writes a character to stdout
 * @c: the character to write
 *
 * Return: On success 1, on error, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				count += _putchar(va_arg(args, int));
			}
			else if (format[i] == 's')
			{
				count += print_s(va_arg(args, char *));
			}
			else if (format[i] == '%')
			{
				count += _putchar('%');
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}
