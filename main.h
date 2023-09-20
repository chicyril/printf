#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

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
int print_bin(va_list args);
void print_rev(char *s);
int count_base_digs(unsigned int num, unsigned int base);
int print_u_int(va_list args);
int cnvrt_to_oct(va_list args);
int cnvrt_to_hex(va_list args);
int cnvrt_to_heX(va_list args);
int print_cust_str(va_list args);
int print_addr(va_list args);
int print_rev_str(va_list args);
int print_rot13(va_list args);

#endif
