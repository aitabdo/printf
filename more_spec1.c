#include "main.h"



/**
 * print_HEX - prints a number in HEXADECIMAL (base 16) in upper case.
 * @args: argument pointer.
 * Return: int (number of chars printed).
 */
int print_HEX(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);

	if (!number)
		return (_putchar('0'));

	return (print_hexadecimal(number, 0, 1));
}

/**
 * print_oct - prints a number in octal (base 8).
 * @args: argument pointer.
 * Return: int (number of chars printed).
 */
int print_oct(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);

	return (print_octal(number));
}

/**
 * print_hex - prints a numbe in hexadecimal (base 16) in lower case.
 * @args: argument pointer.
 * Return: int (number of chars printed).
 */
int print_hex(va_list args)
{
	unsigned int number = va_arg(args, unsigned int);

	if (!number)
		return (_putchar('0'));

	return (print_hexadecimal(number, 0, 0));
}
