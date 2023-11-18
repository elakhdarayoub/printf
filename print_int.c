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
	int digits = 1, divider = 1;
	int n = va_arg(ap, int);
	int num = n, j = 0, j2 = 0, neg = 0;

	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	/* counts number of digits by increasing count and dividing by 10 */
	while ((num / 10) != 0)
	{
		digits++;
		num /= 10;
	}
	/* loops through number from last digit to largest digit */
	for (j = (digits - 1); j >= 0; j--)
	{
		divider = 1;
		for (j2 = 0; j2 < j; j2++)
			divider = divider * 10;
		if (n < 0)
		{
			_putchar('-');
			_putchar((0 - (n / divider)) + '0');
			n = n % divider;
			n = 0 - n;
			neg = 1;
		}
		else
		{
			_putchar((n / divider) + '0');
			n = n % divider;
		}
	}
	return (digits - 1 + neg);
}
