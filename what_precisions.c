#include <stdio.h>
#include "main.h"

/**
<<<<<<< HEAD:what_precisions.c
 * what_precisions - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: what_Precision.
 */
int what_precisions(const char *format, int *i, va_list list)
=======
 * get_precision - calculates precision of printing
 * @format: formatted string to print arguments
 * @i: list arguments to printed
 * @list: lists arguments
 * Return: precision
 */

int get_precision(const char *format, int *i, va_list list)
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c:get_precision.c
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (confirm_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
