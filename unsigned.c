#include "main.h"

/**
 * convert - converter
 * @num: number
 * @base: base
 * @flags: flags
 * @params: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *arrange;
	static char buffer[50];
	char store = 0;
	char *pointer;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		store = '-';
	}
	arrange = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';

	do	{
		*--pointer = arrange[n % base];
		n /= base;
	} while (n != 0);

	if (store)
		*--pointer = store;
	return (pointer);
}

/**
 * print_unsigned - unsigned numbers
 * @xy: pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list xy, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(xy, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(xy, unsigned int);
	else
		l = (unsigned int)va_arg(xy, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - shows address
 * @xy: pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list xy, params_t *params)
{
	unsigned long int n = va_arg(xy, unsigned long int);
	char *new_str;

	if (!n)
		return (_puts("(nil)"));

	new_str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--new_str = 'x';
	*--new_str = '0';
	return (print_number(new_str, params));
}
