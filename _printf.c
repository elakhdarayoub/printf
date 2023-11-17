#include "main.h"

int _printf(const char *format, ...)
{

    int count; 
    int i;
    
    va_list ap;
    if (!format)
        return -1;
    
    count = 0;
    va_start(ap, format);

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
    return count;
}

