#include "main.h"

/**
 * get_specifier_function - Returns the function struct based on the specifier
 * @spec: The specifier character
 * Return: The corresponding function struct or NULL if not found
 */
printf_function get_specifier_function(char spec)
{

    int i;
    printf_function ops[] = {
        {'c', print_char}, {'s', print_str}, {'%', print_mod},
        {'\0', NULL}};
    
    printf_function null_function = {'\0', NULL};

    for (i = 0; ops[i].spec != '\0'; i++)
    {
        if (ops[i].spec == spec)
        {
            return ops[i];
        }
    }
    
    return null_function;
}

