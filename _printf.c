#include "main.h"

/**
 * _printf - A light-weight implementation of standard printf function.
 * @format: Pointer to a constant string.
 * Return: Number of characters been printed.
 */

int _printf(const char *format, ...)
{
	/* Map of all the function but not including precision and size handlers yet */
	/* The NULL struct used to determin the end of The whole array in later usuage */
	/**
	 * map_t ops[] =
	 * {
	 * {"c", print_char},
	 * {"d", print_dec},
	 * {"s", print_str},
	 * {"i", print_int},
	 * {"%", print_mod},
	 * {"b", print_bin},
	 * {"u", print_udec},
	 * {"o", print_oct},
	 * {"x", print_hex},
	 * {"X", print_upHex},
	 * {"S", print_unpr},
	 * {"p", print_ptr},
	 * {"+", plus_handler},
	 * {" ", space_handler},
	 * {"#", hash_handler},
	 * {"l", long_handler},
	 * {"h", short_handler},
	 * {"0", zero_handler},
	 * {"-", justf_handler},
	 * {"r", print_rev},
	 * {"R", rot_handler},
	 * {NULL, NULL}
	 * };
	*/
	map_t ops[] = {{'c', print_char}, {'s', print_str}, {'\0', NULL}};

	int i, j, count = 0;
	va_list ap;

	va_start(ap, format);

	/* If The format passed is NULL in any form just exit with -1 */
	if (!format && !format[0])
		return (-1);

	/* The main loop that replaces specifiers with their corrs args */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			count += _putchar(format[i]);
		else /* we jump in here because format is a % */
		{

			for (j = 0; ops[j].spec != '\0'; j++)
			{

				if (format[i + 1] == ops[j].spec)
				{
					count += ops[j].func(ap);
					i++;
					break;
				}

				else if (ops[j + 1].spec == '\0')
				{
					print_mod();
					if (format[i + 1] == '%')
						i++;
				}

			}

		}
	}
	va_end(ap);
	return (count);
}
