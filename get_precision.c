#include "main.h"

/**
 * get_precision - Calculates the precision for printing.
 *
 * Parameters:
 *  format - The formatted string in which to print the arguments.
 *  arg_index - The index of the current argument.
 *  arg_list - The list of arguments.
 *
 * Returns: The precision value.
 */
int get_precision(const char *format, int *arg_index, va_list arg_list)
{
	int curr_index = *arg_index + 1;
	int precision = -1;

	if (format[curr_index] != '.') {
		return precision;
	}

	precision = 0;

	for (curr_index++; format[curr_index] != '\0'; curr_index++) {
		if (is_digit(format[curr_index])) {
			precision *= 10;
			precision += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*') {
			curr_index++;
			precision = va_arg(arg_list, int);
			break;
		}
		else {
			break;
		}
	}

	*arg_index = curr_index - 1;

	return precision;
}

