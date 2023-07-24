#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int dec_i = *i + 1;
	int argsize = 0;

	if (format[dec_i] == 'l')
		argsize = S_LONG;
	else if (format[dec_i] == 'h')
		argsize = S_SHORT;

	if (argsize == 0)
		*i = dec_i - 1;
	else
		*i = dec_i;

	return (argsize);
}
