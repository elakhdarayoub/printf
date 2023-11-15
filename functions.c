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
	char *str = va_arg(ap, char *);
	int i;

	if (str == NULL)
		return (_printf("(null)"));
	/* calling recursivly our _print to output null if str is NULL */
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_mod - Prints the modulus char.
 * Return: printed %
 */

int print_mod(void)
{
	return (_putchar('%'));
}

/**
 * print_binary - prints binary value of integers
 *
 * @ap: argument pointer to next argument, interger to be printed
 *
 * Return: character count from this function
 */

int print_binary(va_list ap)
{
	int digits = 0, save_digits = 0;
	unsigned long binary = 0, num = 0;
	unsigned long n = va_arg(ap, int);

	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	while (n > 0)
	{
		num = n;
		digits++;
		binary += n % 2;
		n /= 2;
		if ((num == 1) && (n == 1))
			break;
		binary *= 10;
	}
