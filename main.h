#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * struct printf_function - Struct containing a specifier and its function
 * @spec: The specifier character
 * @func: The corresponding function pointer
 */
typedef struct printf_function
{
	char spec;
	int (*func)(va_list);
} printf_function;

int _printf(const char *format, ...);
int _putchar(char c);

int print_char(va_list args);
int print_str(va_list args);
int print_mod(va_list args);
int print_int(va_list ap);

printf_function get_specifier_function(char spec);

int string_length(char *s);
int print_int(va_list ap);
#endif /* MAIN_H */
