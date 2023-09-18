#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct format_specifier - selects a fomat specifier
 * @frmt_spec: format descriptor
 * @arg_formater: pointer to argument formater function
 */
typedef struct format_specifier
{
	char frmt_spec;
	int (*arg_formater)(va_list);
} f_s;
void write_chr(char c);
int _printf(const char *format, ...);
int (*format_specifier(char sd))(va_list args);
int print_str(va_list args);
int print_chr(va_list args);
int print_dec(va_list args);

#endif
