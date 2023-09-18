#include "main.h"

/**
 * write_chr - write characters to stdout
 * @c: character to write
 */
void write_chr(char c)
{
	write(1, &c, 1);
}
