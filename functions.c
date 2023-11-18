#include "main.h"
#include <unistd.h>

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
 * print_char - Print a character
 * @ap: The va_list containing the character to print
 * Return: Number of characters printed
 */
int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	return (_putchar(c));
}

/**
 * print_str - Print a character
 * @ap: The va_list containing the character to print
 * Return: string
 */
int print_str(va_list ap)
{
	int i;

	char *str = va_arg(ap, char *);

	/* calling recursivly our _print to output null if str is NULL */
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_mod - Print a percent sign
 * @ap: The va_list (not used)
 * Return: Always 1 (number of characters printed)
 */

int print_mod(void)
{
	return (_putchar('%'));
}
