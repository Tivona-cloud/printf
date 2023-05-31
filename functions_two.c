#include <stdio.h>
#include "main.h"

/**
 * prints_point - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: pointer.
 */
int prints_point(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long numb_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	numb_address = (unsigned long)address;

	while (numb_address > 0)
	{
		buffer[index--] = map_to[numb_address % 16];
		numb_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	index++;

	return (prints_point(buffer, index, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * cant_print - Prints ascii codes in hexa of non printable characters
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int cant_print(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = 0, offset = 0;
	char *strg = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strg == NULL)
		return (write(1, "(null)", 6));

	while (strg[index] != '\0')
	{
		if (can_print(strg[index]))
			buffer[index + offset] = strg[index];
		else
			offset += add_hexa(strg[index], buffer, index++ offset);

		index++;
	}

	buffer[index + offset] = '\0';

	return (write(1, buffer, index + offset));
}


/**
 * reverser - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int reverser(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *strg;
	int index, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	strg = va_arg(types, char *);

	if (strg == NULL)
	{
		UNUSED(precision);

		strg = ")Null(";
	}
	for (index = 0; strg[index]; index++)
		;

	for (index = index - 1; index >= 0; index--)
	{
		char z = strg[index];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}

/**
 * prints_rot13 - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: characters printed
 */
int prints_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char d;
	char *strg;
	unsigned int index, a;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strg = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strg == NULL)
		strg = "(AHYY)";
	for (index = 0; strg[index]; index++)
	{
		for (a = 0; in[a]; a++)
		{
			if (in[a] == strg[index])
			{
				d = out[a];
				write(1, &d, 1);
				counter++;
				break;
			}
		}
		if (!in[a])
		{
			d = strg[index];
			write(1, &d, 1);
			counter++;
		}
	}
	return (counter);
}
