#include "main.h"

/**
 * print_rev_str - print reversed string
 * @args: string to print
 *
 * Return: number of characters printed
 */
int print_rev_str(va_list args)
{
	char *str = va_arg(args, char *);
	int len;

	if (str == NULL)
	{
		str = "(null)";
		for (len = 0; str[len]; len++)
			;
		write(1, str, len);
		return (len);
	}
	for (len = 0; str[len]; len++)
		;
	print_rev(str);
	return (len);
}

/**
 * print_rot13 - print rot13 of a string
 * @args: string to print
 *
 * Return: number of character printed
 */
int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
	{
		str = "(null)";
		for (len = 0; str[len]; len++)
			;
		write(1, str, len);
		return (len);
	}
	while (*str)
	{
		if (*str >= 'a' && *str <= 'm')
			write_chr((*str) + 13), len++;
		else if (*str >= 'A' && *str <= 'M')
			write_chr((*str) + 13), len++;
		else if (*str > 'm' && *str <= 'z')
			write_chr((*str) - 13), len++;
		else if (*str > 'M' && *str <= 'Z')
			write_chr((*str) - 13), len++;
		else
			write_chr(*str), len++;
		str++;
	}
	return (len);
}
