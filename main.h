#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct format_spec - Maps format specifier with function pointer
 * @spec: specifying character
 * @func: function pointer that matches specifier
 */

typedef struct format_spec
{
	char spec;
	int (*func)(va_list ap);
} map_t;

/* prototype of _printf function */
int _printf(const char *format, ...);

/* prototype of _putchar function */
int _putchar(char c);

/* prototype of print_char function */
int print_char(va_list);

/* prototype of print_str function */
int print_str(va_list);

/* prototype of print_mod function */
int print_mod(void);

/* prototype of print_dec */
int print_dec(va_list);



#endif /* MAIN_H */
