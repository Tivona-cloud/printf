#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct formt  - Struct formed
 * @formt: The format.
 * @func: The function associated.
 */

struct formt
{
	char formt;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct formt formt_t - struct formed
 * @formt: The format.
 * @formt_t: The function associated
 */

typedef struct formt formt_t;

int _printf(const char *format, ...);
int handle_print(const char *formt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

int _char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int _hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

int _non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int _pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int what_flags(const char *format, int *i);
int what_width(const char *format, int *i, va_list list);
int what_precision(const char *format, int *i, va_list list);
int what_size(const char *format, int *i);

int _reverser(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_rot13(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int _number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int _num(int ind, char buff[], int flags, int width,
		int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
