#include "main.h"

/**
 * _isdigit - digit
 * @c: the character
 *
 * Return: 1
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - string
 * @s: string
 *
 * Return: int
 */
int _strlen(char *s)
{
	int r = 0;

	while (*s++)
		r++;
	return (r);
}

/**
 * print_number - number
 * @str: string
 * @params: struct
 *
 * Return: chars
 */
int print_number(char *str, params_t *params)
{
	unsigned int r = _strlen(str);
	int v = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (v)
	{
		str++;
		r--;
	}
	if (params->precision != UINT_MAX)
		while (r++ < params->precision)
			*--str = '0';
	if (v)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - number
 * @str: string
 * @params: struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, v, z, r = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	v = z = (!params->unsign && *str == '-');
	if (v && r < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		v = 0;
	if ((params->plus_flag && !z) ||
		(!params->plus_flag && params->space_flag && !z))
		r++;
	if (v && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !z && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !z &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (r++ < params->width)
		n += _putchar(pad_char);
	if (v && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !z && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !z &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - number
 * @str: string
 * @params:  struct
 *
 * Return: chars
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, v, z, r = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	v = z = (!params->unsign && *str == '-');
	if (v && r < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		v = 0;

	if (params->plus_flag && !z && !params->unsign)
		n += _putchar('+'), r++;
	else if (params->space_flag && !z && !params->unsign)
		n += _putchar(' '), r++;
	n += _puts(str);
	while (r++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
