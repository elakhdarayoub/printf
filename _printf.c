#include "main.h"

/**
 * _printf - A light-weight implementation of standard printf function.
 * @format: pointer to a string
 * Return: number of char printed
 */

int _printf(const char *format, ...)
{
	int count, i;
	va_list ap;

	count = 0;
	va_start(ap, format);
	if (!format || strcmp(format, "%") == 0)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
		}
		else
		{
			if (format[i + 1] == '%')
			{
				count += _putchar('%');
				i++;
			}
			else
			{
				printf_function func = get_specifier_function(format[i + 1]);
				if (func.spec != '\0')
				{
					count += func.func(ap);
					i++;
				}
				else
				{
					count += _putchar('%') + _putchar(format[i + 1]);
					i++;
				}
			}
		}
	}
	va_end(ap);
	return (count);
}
