#include "main.h"

/**
* _printf - A light-weight implementation of standard printf function.
* @format: Pointer to a constant string.
* Return: Number of characters been printed.
*/
int _printf(const char *format, ...)
{
int i, count = 0;
va_list ap;

va_start(ap, format);
if (!format || strcmp(format, "%") == 0)
return (-1);
/* The main loop that replaces specifiers with their corrs args */
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
_putchar('%');
count++;
i++;
continue;
}

else
{
map_t spec = get_specifier_function(format[i + 1]);
if (spec.func != NULL)
{
count += spec.func(ap);
i++;
}

else
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
