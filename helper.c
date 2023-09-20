#include "main.h"

/**
 * print_rev - prints a reversed string
 * @s: string to reverse
 *
 */
void print_rev(char *s)
{
	int len;

	for (len = 0; s[len]; len++)
		;
	while (len > 0)
	{
		write_chr(s[len - 1]);
		len--;
	}
}

/**
 * count_base_digs - checks digit count of a number in another base
 * @num: number to check (base 10)
 * @base: base to check
 *
 * Return: count
 */
int count_base_digs(unsigned int num, unsigned int base)
{
	int count = 0;

	while (num > 0)
	{
		num /= base;
		count++;
	}
	return (count);
}

