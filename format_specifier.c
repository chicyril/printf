#include "main.h"

/**
 * format_specifier - selects appropriate handler function for a
 * specifier
 * @spec: specifier decriptor to check
 *
 * Return: a pointer to the appropriate function
 */
int (*format_specifier(char spec))(va_list args)
{
	f_s arg_formater_select[] = {
		{'c', print_chr},
		{'s', print_str},
		{'d', print_dec},
		{'i', print_dec},
		{'\0', NULL}
	};

	int i = 0;

	for (i = 0; arg_formater_select[i].frmt_spec != '\0'; i++)
		if (spec == arg_formater_select[i].frmt_spec)
			return (arg_formater_select[i].arg_formater);
	return (NULL);
}
