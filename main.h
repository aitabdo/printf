#ifndef MAIN_H
#define MAIN_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<unistd.h>

int print_str(char *str);
int _putchar(char c);
int _printf(const char *format, ...);

/**
 * print_str - A function that prints a string
 * @str: our string
 * Return: int(length of str).
 */
int print_str(char *str)
{
	unsigned int j = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (*str)
	{
		_putchar(*str);
		j++;
		str++;
	}
	return (j);
}



#endif
