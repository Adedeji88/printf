/*
* File: _printf.c
* Auth: Tijani Mustapha A.
*	Daniel Ikuyajolu G.
*/
#include "main.h"
#include <stdio.h>

/**
 * _printf - takes a string and args of each '%'
 * and prints them
 * @format: initial str containing % plus
 * char denoting type and number of args
 * @...: variable list of arguments
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int x, y, count = 0;
	va_list fst;
	interface ids[] = {
		{'c', _print_char},
		{'s', _print_string},
		{'i', _print_int},
		{'d', _print_int},
		{'%', _print_mod},
		{'\0', NULL}
	};

	va_start(fst, format); /* fst means 1st */
	for (x = 0; format[x]; x++)
		if (format[x] == '%')
		{
			x++;
			for (; format[x] != '\0'; x++)
			{
				for (y = 0; ids[y].id != '\0'; y++)
					if (format[x] == ids[y].id)
					{
						count += ids[y].func(fst);
						break;
					}
				if (ids[y].id)
					break;
			}
			if (format[x] == '\0')
				return (-1);
		}
		else
		{
			write(1, &format[x], 1);
			count += 1;
		}

	va_end(fst);
	return (count);
}
