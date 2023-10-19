#include "main.h"
/**
* print_string - a function that prints a string.
* @str: string to be printed.
* Return: int (number of chars been printed).
*/
int print_string(char *str)
{
	unsigned long int i = 0;

	if (str == NULL)
		return (-1);
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
/**
* print_char - a function that prints char.
* @c: char to be printed.
* Return: int (1 char printed).
*/
int print_char(char c)
{
	return (_putchar(c));
}
