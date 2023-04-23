#include "main.h"

/****************** PRINT POINTER ******************/

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2;
		unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & (F_PLUS | F_SPACE))
		extra_c = flags & F_PLUS ? '+' : ' ', length++;
	ind++;
	int padd_start = 1;

	return (write_pointer(buffer, ind,
				length, width, flags, padd, extra_c, padd_start));
}
/************************* PRINT NON PRINTABLE *************************/

/**
 * print_non_printable - Prints ASCII codes in hexadecimal
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags (unused)
 * @width: Width specifier (unused)
 * @precision: Precision specification (unused)
 * @size: Size specifier (unused)
 * Return: Number of characters printed
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int i = 0, j = 0;

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
		{
			buffer[j] = str[i];
			j++;
		}
		else
		{
			j += append_hexa_code(str[i], buffer, j);
		}
		i++;
	}

	buffer[j] = '\0';

	return (write(1, buffer, j));
}
/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		return (write(1, ")Null(", 6));
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		continue;
	}

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		count += write(1, &z, 1);
	}

	return (count);
}
/************************* PRINT A STRING IN ROT13 ***********************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Field width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	const char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

