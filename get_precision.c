#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int dec_i = *i + 1;
	int precision = -1;

	if (format[dec_i] != '.')
		return (precision);

	precision = 0;

	for (dec_i += 1; format[dec_i] != '\0'; dec_i++)
	{
		if (is_digit(format[dec_i]))
		{
			precision *= 10;
			precision += format[dec_i] - '0';
		}
		else if (format[dec_i] == '*')
		{
			dec_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = dec_i - 1;

	return (precision);
}
