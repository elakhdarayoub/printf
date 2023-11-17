#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

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

int handle_flags(char flag, va_list args);
int handle_length_modifier(char modifier, va_list args);
int get_number(const char *format, int *i);

printf_function get_specifier_function(char spec);

#endif /* MAIN_H */
