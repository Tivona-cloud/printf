#include <stdio.h>
#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @formt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *formt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	formt_t formt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned},  {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', get_reverse}, {'R', prints_rot13}, {'\0', NULL}
	};
	for (i = 0; formt_types[i].formt != '\0'; i++)
		if (formt[*ind] == formt_types[i].formt)
			return (formt_types[i].func(list, buffer, flags, width, precision, size));

	if (formt_types[i].formt == '\0')
	{
		if (formt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (formt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (formt[*ind] != ' ' && formt[*ind] != '%')
				--(*ind);
			if (formt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &formt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
