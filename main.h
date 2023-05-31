#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
<<<<<<< HEAD
#define BUFF_SIZE 1024

=======
#define BUFF_SIZE 102
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
<<<<<<< HEAD

=======
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c
#define S_LONG 2
#define S_SHORT 1

/**
<<<<<<< HEAD
 * struct formt - Struct formed
 * @formt: The format.
 * @func: The function associated.
 */
struct formt
{
	char formt;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct formt format_t - Struct formed
 *
 * @formt: The format.
 * @format_t: The function associated.
 */
typedef struct formt format_t;
=======
 * typedef struct fmt fmt_t - Struct
 * @fmt: the format
 * @fm_t: the function associated with
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
}

/**
 * typedef struct fmt fmt_t - Struct
 * @fmt: the format
 * @fm_t: the function associated with
 */

typedef struct fmt fmt_t;
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c

int _printf(const char *format, ...);
int lhandles_print(const char *formt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

<<<<<<< HEAD
int _char(va_list types, char buffer[],
=======
int print_char(va_list types, char buffer[],
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c
	int flags, int width, int precision, int size);
int _string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
<<<<<<< HEAD
int _percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _int(va_list types, char buffer[],
=======
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size;

int print_int(va_list types, char buffer[],
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c
	int flags, int width, int precision, int size);
int _binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

<<<<<<< HEAD
int cant_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int prints_point(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int what_flags(const char *format, int *i);
int what_width(const char *format, int *i, va_list list);
int what_precisions(const char *format, int *i, va_list list);
int what_sizes(const char *format, int *i);

int reverser(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int prints_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handles_write_char(char c, char buffer[],
=======
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int _number(int ind, char buffer[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int _pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int _unsigned(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

<<<<<<< HEAD
int can_print(char);
int add_hexa(char, char[], int);
int confirm_digit(char);
=======
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
>>>>>>> f1d696f3793b148c59c871b12396739729d8c23c

long int converts_size(long int num, int size);
long int convert_to_unsigned(unsigned long int num, int size);

#endif
