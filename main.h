#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct format_spec - matches format specifier with function pointer
 * @str: specifying character
 * @func: function pointer that matches specifier
 */

typedef struct format_spec
{
	char *str;
	int (*func)(va_list ap);
} spec_t;

/* declaration of _printf function */
int _printf(const char *format, ...);

/* declaration of _putchar function */
int _putchar(char c);

/* declaration of print_char function */
int print_char(va_list ap);

/* declaration of print_string function */
int print_string(va_list ap);

/* declaration of print_perc function */
int print_perc(va_list ap);



#endif /* MAIN_H */
