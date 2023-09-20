#include "main.h"

/**
 * print_u_int - print unsigned ints
 * @args: number to print
 *
 * Return: number of char printed
 */
int print_u_int(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp, div = 1, digs = 1, count = 0;

	if (num == 0)
	{
		write_chr('0');
		return (count + 1);
	}
	temp = num;
	while (temp / 10)
	{
		temp /= 10;
		digs++;
		div *= 10;
	}
	while (digs > 0)
	{
		write_chr(num / div + '0');
		count++;
		num %= div;
		div /= 10;
		digs--;
	}
	return (count);
}

/**
 * cnvrt_to_oct - converts to number to octal and print
 * @args: number to convert
 *
 * Return: count of characters printed
 */
int cnvrt_to_oct(va_list args)
{
	int i, base = 8, len = 0;
	unsigned int num = va_arg(args, unsigned int);
	char *digs = NULL;

	if (num == 0)
	{
		write_chr('0');
		return (1);
	}
	len = count_base_digs(num, base);
	digs = (char *)malloc(len + 1);
	if (digs == NULL)
		return (-1);
	for (i = 0; i < len; i++)
	{
		digs[i] = (num % base + '0');
		num /= base;
	}
	digs[i] = '\0';
	print_rev(digs);
	free(digs);
	digs = NULL;
	return (len);
}

/**
 * cnvrt_to_hex - converts a number to hex and print
 * @args: number to convert
 *
 * Return: count ot characters printed
 */
int cnvrt_to_hex(va_list args)
{
	int i, digx = 0, base = 16, len = 0;
	unsigned int num = va_arg(args, unsigned int);
	char *digs = NULL;

	if (num == 0)
	{
		write_chr('0');
		return (1);
	}
	len = count_base_digs(num, base);
	digs = (char *)malloc(len + 1);
	if (digs == NULL)
		return (-1);
	for (i = 0; i < len; i++)
	{

		digx = num % base;
		if (digx > 9)
			digx = digx - 10 + 'a';
		else
			digx += '0';
		digs[i] = digx;
		num /= base;
	}
	digs[i] = '\0';
	print_rev(digs);
	free(digs);
	digs = NULL;
	return (len);
}

/**
 * cnvrt_to_heX - converts a number to hex and print
 * @args: number to convert
 *
 * Return: count ot characters printed
 */
int cnvrt_to_heX(va_list args)
{
	int i, digX = 0, base = 16, len = 0;
	unsigned int num = va_arg(args, unsigned int);
	char *digs = NULL;

	if (num == 0)
	{
		write_chr('0');
		return (1);
	}
	len = count_base_digs(num, base);
	digs = (char *)malloc(len + 1);
	if (digs == NULL)
		return (-1);
	for (i = 0; i < len; i++)
	{
		digX = num % base;
		if (digX > 9)
			digX = (digX - 10 + 'A');
		else
			digX += '0';
		digs[i] = digX;
		num /= base;
	}
	digs[i] = '\0';
	print_rev(digs);
	free(digs);
	digs = NULL;
	return (len);
}

/**
 * print_cust_str - print string for custom specifier S
 * @args: string to print
 *
 * Return: count of characters printed
 */
int print_cust_str(va_list args)
{
	int i, count = 0;
	char *str = va_arg(args, char *), u_nib, l_nib;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 0 || (str[i] > 31 && str[i] < 127))
		{
			write_chr(str[i]);
			count++;
			continue;
		}
		write_chr('\\');
		write_chr('x');
		count += 2;
		u_nib = str[i] >> 4;
		l_nib = str[i] & 15;
		write_chr(u_nib < 10 ? u_nib + '0' : u_nib - 10 + 'A');
		count++;
		write_chr(l_nib < 10 ? l_nib + '0' : l_nib - 10 + 'A');
		count++;
	}
	return (count);
}
