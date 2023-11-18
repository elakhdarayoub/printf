#include "main.h"

/**
 * get_specifier_function - Returns the function pointer based on the specifier
 * @spec: The specifier character
 * Return: The corresponding function pointer or NULL if not found
 */
map_t get_specifier_function(char spec)
{
	map_t null_func;

	map_t ops[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_mod},
		{'\0', NULL}};
	int i;

	for (i = 0; ops[i].spec != '\0'; i++)
	{
		if (ops[i].spec == spec)
		{
			return (ops[i]);
		}
	}

	null_func.spec = '\0';
	null_func.func = NULL;
	return (null_func);
}

