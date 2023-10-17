#include "main.h"

/**
 * print_from_to - print addresses
 * @start: start
 * @stop: stop
 * @except: except
 *
 * Return: number
 */
int print_from_to(char *start, char *stop, char *except)
{
	int add = 0;

	while (start <= stop)
	{
		if (start != except)
			add += _putchar(*start);
		start++;
	}
	return (add);
}

/**
 * print_rev - string reverse
 * @xy: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list xy, params_t *params)
{
	int len, add = 0;
	char *str = va_arg(xy, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			add += _putchar(*str);
	}
	return (add);
}

/**
 * print_rot13 -  string rot13
 * @xy: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list xy, params_t *params)
{
	int r, k;
	int c = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(xy, char *);
	(void)params;

	r = 0;
	k = 0;
	while (a[r])
	{
		if ((a[r] >= 'A' && a[r] <= 'Z')
		    || (a[r] >= 'a' && a[r] <= 'z'))
		{
			k = a[r] - 65;
			c += _putchar(arr[k]);
		}
		else
			c += _putchar(a[r]);
		r++;
	}
	return (c);
}
