#include "main.h"

/**
 * _printf - A light-weight implementation of standard printf function.
 * @format: Pointer to a constant string.
 * Return: Number of characters been printed.
 */
int _printf(const char *format, ...)
{
	map_t ops[] = {{'c', print_char}, {'s', print_str}, {'\0', NULL}};
	int i, j, specf = 0, count = 0;
	va_list ap;

	va_start(ap, format);
	if (!format || strcmp(format, "%") == 0)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			count += _putchar(format[i]);
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i++;
			}
			else
			{
				for (j = 0; ops[j].spec != '\0'; j++)
				{
					if (format[i + 1] == ops[j].spec)
					{
						count += ops[j].func(ap);
						i++;
						specf = 1;
						break;
					}
				}
				if (!specf)
				{
					_putchar('%');
					_putchar(format[i + 1]);
					count += 2;
					i++;
				}
			}
		}
	}
	va_end(ap);
	return (count);
}
