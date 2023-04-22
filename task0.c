#include "main.h"
#include <unistd.h>

/**
 * print_c - A function that prints a char
 * @c: character to print
 * Return: Number of characters printed (always 1)
 */
int print_c(va_list c)
{
	char character = (char)va_arg(c, int);

	_putchar(character);
	return (1);
}

/**
 * print_s - A function that prints a string
 * @s: string to print
 * Return: Number of characters printed
 */
int print_s(va_list s)
{
	char *str = va_arg(s, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
		_putchar(str[i++]);

	return (i);
}

/**
 * print_percent - A function that prints the percent symbol
 * @list: list of arguments (unused)
 * Return: Number of characters printed (always 1)
 */
int print_percent(va_list list)
{
	(void)list;
	_putchar('%');
	return (1);
}

