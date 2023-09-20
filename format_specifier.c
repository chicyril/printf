#include "main.h"

/**
 * format_specifier - selects appropriate handler function for a specifier
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
		{'b', print_bin},
		{'u', print_u_int},
		{'o', cnvrt_to_oct},
		{'x', cnvrt_to_hex},
		{'X', cnvrt_to_heX},
		{'S', print_cust_str},
		{'p', print_addr},
		{'r', print_rev_str},
		{'R', print_rot13},
		{'\0', NULL}
	};
	int i = 0;

	for (i = 0; arg_formater_select[i].frmt_spec != '\0'; i++)
		if (spec == arg_formater_select[i].frmt_spec)
			return (arg_formater_select[i].arg_formater);
	return (NULL);
}
