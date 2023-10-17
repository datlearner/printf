#include "main.h"

/**
 * _printf - prints to the standard output
 * @format: format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int add = 0;
	va_list xy;
	char *p, *start;

	params_t params = PARAMS_INIT;

	va_start(xy, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, xy);
		if (*p != '%')
		{
			add += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, xy);
		p = get_precision(p, &params, xy);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			add += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			add += get_print_func(p, xy, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(xy);
	return (add);
}
