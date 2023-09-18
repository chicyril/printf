#include "main.h"

/**
 * _printf - print formated output
 * @format: format string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*arg_formater)(va_list args), i, count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == ' ' || !format[i])
				return (-1);
			if (format[i] == '%')
			{
				write_chr('%');
				count++;
				continue;
			}
			arg_formater = format_specifier(format[i]);
			if (arg_formater == NULL)
			{
				write_chr('%');
				write_chr(format[i]);
				count += 2;
				continue;
			}
			count += arg_formater(args);
			continue;
		}
		write_chr(format[i]);
		count++;
	}
	va_end(args);
	return (count);
}
