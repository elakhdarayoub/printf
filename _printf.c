#include "main.h"

/**
 * _printf - function to print
 * @format: string to be passed
 * Return: 0
 */

int _printf(const char *format, ...)
{

	map_t ops[] = {
		{'c', print_char}, {'s', print_str}, {'d', print_int}, {'i', print_int}, {'\0', NULL}};

	int i, j, count = 0;

	int count, i;

	va_list ap;

	count = 0;
	va_start(ap, format);

	if (!format)
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

