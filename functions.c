#include "main.h"
#include <string.h>

/**
 * _putchar - Prints a char.
 * @c: The char to print.
 * Return: 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints the %c specifier.
 * @ap: char to be printed
 * Return: 1.
 */

int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	return (_putchar(c));
}

/**
 * print_str - Prints a string.
 * @ap: The string to print.
 * Return: The number of chars printed.
 */

int print_str(va_list ap)
{
	char *x = va_arg(ap, char*), *nil_string = "(null)";
	int y, len, len2 = strlen(nil_string);

	if (x == NULL)
	{
		for (y = 0; nil_string[y]; y++)
			_putchar(nil_string[y]);
		return (len2 - 1);
	}
	len = strlen(x);
	for (y = 0; y < len ; y++)
		_putchar(x[y]);
	return (len - 1);
}

/**
 * print_mod - Prints the modulus char.
 * Return: printed %
 */

int print_mod(void)
{
	return (_putchar('%'));
}
