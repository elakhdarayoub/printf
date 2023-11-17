#include "main.h"

/**
 * _printf - A light-weight implementation of standard printf function.
 * @format: Pointer to a constant string.
 * Return: Number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    map_t ops[] = {
        {'c', print_char}, {'s', print_str}, {'%', print_mod}, {'\0', NULL}};

    int i, j, count = 0, specf = 0;
    va_list ap;

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
                for (j = 0; ops[j].spec != '\0'; j++)
                {
                    if (format[i + 1] == ops[j].spec)
                    {
                        count += ops[j].func(ap);
                        specf = 1;
                        i++;
                        break;
                    }
                }

                if (!specf)
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
