#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
* struct intfce - interface for printing
* @id: the character, which identifies the type of arg
* @func: function to run if id matches
*/
typedef struct intfce
{
	char id;
	int (*func)(va_list);
} interface;

int _printf(const char *format, ...);
int _print_char(va_list ls);
int _print_mod(va_list ls);
int _print_string(va_list ls);
int _print_int(va_list ls);

#endif /* MAIN */
