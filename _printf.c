#include "main.h"

/* Function prototypes */
void print_buffer(char buffer[], int *buff_ind);

/* Function definitions */

/**
 * _printf - Printf function
 * @format: format string
 * Return: Number of printed characters, or -1 on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, printed_chars = 0, printed;
	int flags, width, precision, size, buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += BUFF_SIZE;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			printed = handle_print(format, &i, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
			{
				va_end(args);
				return (-1);
			}
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of characters to print
 * @buff_ind: Pointer to index of last used position in buffer
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}

