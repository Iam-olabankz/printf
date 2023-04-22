#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format.
 * @format: format string containing zero or more directives.
 *
 * Return: the number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list arg_list;

	va_start(arg_list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += write(1, &va_arg(arg_list, int), 1);
					break;
				case 's':
					printed_chars += write(1, va_arg(arg_list, char *), strlen(va_arg(arg_list, char *)));
					break;
				case '%':
					printed_chars += write(1, "%", 1);
					break;
				default:
					break;
			}
		}
		else
		{
			printed_chars += write(1, format, 1);
		}
		format++;
	}

	va_end(arg_list);

	return printed_chars;
}

