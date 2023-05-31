#include <stdio.h>
#include "main.h"

void prints_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int index, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buff_ind++] = format[index];
			if (buff_ind == BUFF_SIZE)
				prints_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			prints_buffer(buffer, &buff_ind);
			flags = what_flags(format, &index);
			width = what_width(format, &index, list);
			precision = what_precisions(format, &index, list);
			size = what_sizes(format, &index);
			index++;
			printed = lhandles_print(format, &index, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	prints_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * prints_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void prints_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
