#include "main.h"

/**
<<<<<<< HEAD:what_sizes.c
 * what_sizes - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int what_sizes(const char *format, int *i)
=======
 * get_size - Calculates size to cast the argument
 * @format: Formatted string to print arguments
 * @i: Lists arguments printed
 * Return: Precision
 */

int get_size(const char *format, int *i)
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c:get_size.c
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
