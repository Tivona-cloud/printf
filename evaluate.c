#include <stdio.h>
#include "main.h"

/**
 * can_print - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if true, 0 otherwise
 */
int can_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hexa - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @index: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int add_hexa(char ascii_code, char buffer[], int index)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = map_to[ascii_code / 16];
	buffer[index] = map_to[ascii_code % 16];

	return (3);
}

/**
 * confirm_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if true, 0 otherwise
 */
int confirm_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * converts_size - Casts a number to the specified size
 * @numb: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted numb
 */
long int converts_size(long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * convert_to_unsigned - Casts a number to the specified size
 * @numb: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted numb
 */
long int convert_to_unsigned(unsigned long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}
