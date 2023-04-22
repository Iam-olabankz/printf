#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _puts(char *str)
{
	int i = 0;
	while (str[i])
		_putchar(str[i++]);
	return (i);
}

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
				count += _puts(va_arg(args, char *));
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

