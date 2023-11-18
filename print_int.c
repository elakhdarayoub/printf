#include "main.h"

/**
 * print_int - prints integers
 *
 * @ap: argument pointer to next argument, interger to be printed
 *
 * Return: character count from this function
 */

int print_int(va_list ap)
{
	int a, expo = 1, len = 0;
	unsigned int n;

	a = va_arg(integ, int);

	if (a < 0)
	{
		len = len + _putchar('-');
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		len = len + _putchar(n / expo + '0');
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}
