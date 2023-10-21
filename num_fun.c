#include "main.h"

/**
 * print_number - prints integer.
 * @a: integer to be printed.
 * Return: int (number of digits printed).
 */
int print_number(unsigned int a)
{
	int pow = 1, length = 0;

	while ((a / pow) > 9)
		pow *= 10;

	while (pow > 0)
	{
		length += _putchar(a / pow + '0');
		a %= pow;
		pow /= 10;
	}
	return (length);
}

/**
 * print_string - prints string.
 * @str: string to be printed.
 * Return: int (number of characters printed).
 */
int print_string(char *str)
{
	int length = 0;

	while (*str)
	{
		length += _putchar(*str);
		str++;
	}
	return (length);
}

/**
 * print_binary - prints a a in binary format, recursively.
 * @a: a to be printed.
 * Return: int (number of digits printed).
 */
int print_binary(unsigned int a)
{
	int i = 0;

	if (a == 0)
	{
		return (0);
	}
	else
	{
		i += print_binary(a / 2);
		i += _putchar((a % 2) + '0');
	}
	return (i);
}

/**
 * print_octal - prints (a) a in octal format in a rucursive way.
 * @a: a to be printed.
 * Return: int (number of digits to be printed).
 */
int print_octal(unsigned int a)
{
	int i = 0;

	if (a < 8)
	{
		i += _putchar(a + '0');
	}
	else
	{
		i += print_octal((a / 8));
		i += _putchar((a % 8) + '0');
	}
	return (i);
}

/**
 * print_hexadecimal - prints (a) a in hexadecimal format.
 * in upper case - 2 characters.
 * @a: a to be printed.
 * @prefix: flag to indicate if '0' prefix should be printed, 1 = n, 0 = y.
 * @caps: flag to indicate if upper case should be used, 1 = n, 1 = y.
 * Return: int (number of digits printed).
 */
int print_hexadecimal(unsigned long int a, int prefix, int caps)
{
	int i = 0;

	if (a < 16)
	{
		if (!prefix)
			i += _putchar('0');
		if (a < 10)
			i += _putchar(a + '0');
		else
			i += caps ?
				_putchar((a - 10) + 'A') : _putchar((a - 10) + 'a');
	}
	else
	{
		prefix = 1;
		i += print_hexadecimal((a / 16), prefix, caps);
		i += print_hexadecimal((a % 16), prefix, caps);
	}
	return (i);
}
