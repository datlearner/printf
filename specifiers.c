#include "main.h"

/**
 * get_specifier - format function
 * @s: string
 * Return: bytes printed
 */

int (*get_specifier(char *s))(va_list xy, params_t *params)

{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int r = 0;

	while (specifiers[r].specifier)
	{
		if (*s == specifiers[r].specifier[0])
		{
			return (specifiers[r].f);
		}
		r++;
	}
	return (NULL);
}

/**
 * get_print_func - format
 * @s: string
 * @xy: pointer
 * @params: parameters struct
 * Return: bytes printed
 */

int get_print_func(char *s, va_list xy, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(xy, params));
	return (0);
}

/**
 * get_flag - flag functions
 * @s: format string
 * @params: the parameters struct
 * Return: flag valid
 */

int get_flag(char *s, params_t *params)

{
	int r = 0;

	switch (*s)
	{
		case '+':
			r = params->plus_flag = 1;
			break;
		case ' ':
			r = params->space_flag = 1;
			break;
		case '#':
			r = params->hashtag_flag = 1;
			break;
		case '-':
			r = params->minus_flag = 1;
			break;
		case '0':
			r = params->zero_flag = 1;
			break;
	}
	return (r);
}

/**
 * get_modifier - modifier function
 * @s: string
 * @params: structure
 * Return: modifier
 */

int get_modifier(char *s, params_t *params)
{
	int r = 0;

	switch (*s)
	{
		case 'h':
			r = params->h_modifier = 1;
			break;
		case 'l':
			r = params->l_modifier = 1;
			break;
	}
	return (r);
}

/**
 * get_width - width
 * @s: string
 * @params: the parameters struct
 * @xy: pointer
 * Return: pointer
 */

char *get_width(char *s, params_t *params, va_list xy)
{
	int int_number = 0;

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
	params->width = int_number;
	return (s);
}
