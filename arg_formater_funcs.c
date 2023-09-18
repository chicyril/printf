#include "main.h"

/**
 * print_chr - print character
 * @args: character to print
 *
 * Return: number of characters printed
 */
int print_chr(va_list args)
{
	char c = (unsigned char)(va_arg(args, int));

	write_chr(c);
	return (1);
}

/**
 * print_str - print strings
 * @args: string to print
 *
 * Return: number of character printed
 */
int print_str(va_list args)
{
	int i, count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
		;
	write(1, str, i);
	count += i;
	return (count);
}

/**
 * print_dec - print decimals and ints
 * @args: argument to write
 *
 * Return: count of digits written
 */
int print_dec(va_list args)
{
	int num = va_arg(args, int);
	int temp, div = 1, digs = 1, count = 0;

	if (num == 0)
	{
		write_chr('0');
		return (count + 1);
	}
	if (num < 0)
	{
		write_chr('-');
		count++;
		num *= -1;
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
