#include <stdio.h>
#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_to_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}i

	i++;

	return (print_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * _octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
<<<<<<< HEAD:functions_one.c
int _octal(va_list types, char buffer[],
=======

int print_octal(va_list types, char buffer[],
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c:functions1.c
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_to_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (print_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * _hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

<<<<<<< HEAD:functions_one.c

/**
 * _hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
=======
/**
 * print_hexa_upper - prints unsigned number in upper hexadecimal notation
 * @types: lists of arguments
 * @buffer: buffer array handles print
 * @flags:  calculates flags
 * @width: to get width
 * @precision: precision specifications
 * @size: size specifies
 * Return: numbers  chars printed
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c:functions1.c
 */
int _hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

<<<<<<< HEAD:functions_one.c

/**
 * _hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
=======
/**
 * print_hexa - prints hexadecimal number in lower or upper
 * @types: lists arguments
 * @map_to: array of values to map numbers
 * @buffer: buffer array handles print
 * @flags: calculate flags
 * @flag_ch: calculate flags
 * @width: to get width
 * @precision: precision specifications
 * @size: size specifier
 * @size:size specifications
 * Return: Number chars printed
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c:functions1.c
 */
int _hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_to_unsgned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (print_unsigned(0, i, buffer, flags, width, precision, size));
}
