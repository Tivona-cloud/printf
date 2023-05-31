#include <stdio.h>
#include "main.h"

/**
<<<<<<< HEAD:what_width.c
 * what_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int what_width(const char *format, int *i, va_list list)
=======
 * get_precision - calculates precision of printing
 * @format: formatted string to print arguments
 * @i: list arguments to printed
 * @list: lists arguments
 * Return: precision
 */

int get_width(const char *format, int *i, va_list list)
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c:get_width.c
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (confirm_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
