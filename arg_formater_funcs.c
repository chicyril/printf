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
	int len, count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (len = 0; str[len] != '\0'; len++)
		;
	write(1, str, len);
	count += len;
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
	long num = (long)va_arg(args, int), temp = 0;
	int div = 1, digs = 1, count = 0;

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

/**
 * print_bin - print binaries
 * @args: number to convert to binary
 *
 * Return: count of characters printed
 */
int print_bin(va_list args)
{
	unsigned int tmp = 0, num = va_arg(args, unsigned int);
	int i, count = 0, bit_pos = 0;

	if (num == 0)
	{
		write_chr('0');
		return (count + 1);
	}
	tmp = num;
	while (tmp > 0)
	{
		tmp >>= 1;
		bit_pos++;
	}
	for (i = bit_pos - 1; i >= 0; i--)
	{
		write_chr(((num >> i) & 1) + '0');
		count++;
	}
	return (count);
}

/**
 * print_addr - print address of value stored in a pointer
 * @args: list to extract the value
 *
 * Return: number of character printed
 */
int print_addr(va_list args)
{
	void *address = va_arg(args, void *);
	unsigned long addr, temp, chr;
	int i = 0, nibs = 0;
	char *out = NULL, *nuladd = NULL;

	addr = (unsigned long)address;
	if (addr == 0)
	{
		nuladd = (char *)address;
		nuladd = "(nil)";
		for(; nuladd[i]; i++)
			write_chr(nuladd[i]);
		return (i);
	}
	temp = addr;
	while (temp)
	{
		temp >>= 4;
		nibs++;
	}
	out = malloc(nibs + 3);
	if (out == NULL)
		return (-1);
	while (addr)
	{
		chr = (addr & 0xf);
		out[i++] = (chr < 10) ? chr + '0' : chr - 10 + 'a';
		addr >>= 4;
	}
	out[i++] = 'x';
	out[i++] = '0';
	out[i] = '\0';
	print_rev(out);
	free(out);
	return(nibs + 2);
}
