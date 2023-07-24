#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int dec_i;
	int width = 0;

	for (dec_i = *i + 1; format[dec_i] != '\0'; dec_i++)
	{
		if (is_digit(format[dec_i]))
		{
			width *= 10;
			width += format[dec_i] - '0';
		}
		else if (format[dec_i] == '*')
		{
			dec_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = dec_i - 1;

	return (width);
}
