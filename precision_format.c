#include "main.h"

/**
 * get_precision - precision string
 * @s: string
 * @params: the parameters struct
 * @xy: pointer
 * Return: new pointer
*/

char *get_precision(char *s, params_t *params, va_list xy)
{
	int int_number = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		int_number = va_arg(xy, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			int_number = int_number * 10 + (*s++ - '0');
	}
	params->precision = int_number;
	return (s);
}
