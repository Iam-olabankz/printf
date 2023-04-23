#include "main.h"

/**
 * get_flags - Calculates active flags
 *
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 *
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	const char VALID_FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int VALID_FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, curr_i;
	int flags = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; VALID_FLAG_CHARS[j] != '\0'; j++)
		{
			if (format[curr_i] == VALID_FLAG_CHARS[j])
			{
				flags |= VALID_FLAG_VALUES[j];
				break;
			}
		}

		if (VALID_FLAG_CHARS[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

