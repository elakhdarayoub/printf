#include "main.h"

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
 * @ap.
 * Return: 1.
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);
	return(_putchar(c));
}

/**
 * print_str - Prints a string.
 * @ap: The string to print.
 * Return : The number of chars printed.
 */
int print_str(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i;

	for(i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_mod: Prints the modulus char.
 * Return: 1 which the length of printed chars.
 */
int print_mod(va_list ap)
{
	(void *)ap;
	return (_putchar('%'));
}
