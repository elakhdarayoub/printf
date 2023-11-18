#include "main.h"

/**
 * _printf - A light-weight implementation of standard printf function.
 * @format: Pointer to a constant string.
 * Return: Number of characters been printed.
 */
int _printf(const char *format, ...)
{
	map_t ops[] = {
		{'c', print_char}, {'s', print_str}, {'\0', NULL}};

	int i, j, count = 0;
	va_list ap;
	int specf;

	specf = 0;
	va_start(ap, format);
	/* If The format passed is NULL in any form just exit with -1 */
	/* This */
	if (!format && strcmp(format, "%") == 0)
		return (-1);
	/* The main loop that replaces specifiers with their corrs args */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			count += _putchar(format[i]);

		/* we jump in here because format is a % */
		else
		{
			if (format[i + 1] == '%')
			{
				print_mod();
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
				/* next char spec == null no match found call print_mod() */
				}

				if (!specf)
				{
					print_mod();
					count++;
				}
			}
		}
	}
	va_end(ap);
	return (count);
}
/* 1 */
/* 2 */
/* 3 */
/* 4 */
/* 5 */
/* 6 */
/* 7 */
/* 8 */
/* 9 */
/* 10 */
/* 11 */
/* 12 */
/* 13 */
/* 14 */
/* 15 */
/* 16 */
/* 17 */
/* 18 */
/* 19 */
/* 20 */
