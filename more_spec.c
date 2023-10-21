#include "main.h"

/**
 * print_rev - prints string in reverse.
 * @args: argument pointer.
 * Return: int (number of characters printed).
 */
int print_rev(va_list args)
{
	char *string = va_arg(args, char *);
	int length = 0, num_to_print = 0;

	if (!string)
		return (-1);

	while (*string)
	{
		string++;
		length++;
	}

	while (length > 0)
	{
		string--;
		num_to_print += _putchar(*string);
		length--;
	}

	return (num_to_print);
}

/**
 * print_addr - prints address.
 * @args: argument pointer.
 * Return: int (number of characters printed).
 */
int print_addr(va_list args)
{
	unsigned long int a = va_arg(args, unsigned long int);
	int num_to_print = 0;

	if (!a)
	{
		return (print_string("(nil)"));
	}

	num_to_print += print_string("0x");
	num_to_print += print_hexadecimal(a, 1, 0);

	return (num_to_print);
}

/**
 * print_bin - prints an unsigned int in binary format.
 * @args: argument pointer.
 * Return: int(number of digits printed).
 */
int print_bin(va_list args)
{
	unsigned int a = va_arg(args, unsigned int);

	if (a == 0)
	{
		return (_putchar('0'));
	}

	if (a == 1)
	{
		return (_putchar('1'));
	}
	else
	{
		return (print_binary(a));
	}
}

/**
 * print_rot13 - prints a string in rot13 format.
 * @args: argument pointer.
 * Return: int (number of characters printed).
 */
int print_rot13(va_list args)
{
	char *string = va_arg(args, char *);
	int i, num_to_print = 0;

	if (!string)
		return (-1);

	for (i = 0; string[i]; i++)
	{
		if ((string[i] >= 'a' && string[i] <= 'm') ||
				(string[i] >= 'A' && string[i] <= 'M'))
		{
			num_to_print += _putchar(string[i] + 13);
		}
		else if ((string[i] >= 'n' && string[i] <= 'z') ||
				(string[i] >= 'N' && string[i] <= 'Z'))
		{
			num_to_print += _putchar(string[i] - 13);
		}
		else
		{
			num_to_print += _putchar(string[i]);
		}
	}

	return (num_to_print);
}

/**
 * print_STR - prints a string, replacing non-printable chars.
 * @args: argument pointer.
 * Return: int (number of chars printed).
 */
int print_STR(va_list args)
{
	char *str = va_arg(args, char *);
	int i, num_char_printed = 0;

	if (!str)
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			num_char_printed += _putchar('\\');
			num_char_printed += _putchar('x');
			num_char_printed += print_hexadecimal(str[i], 0, 1);
		}
		else
		{
			num_char_printed += _putchar(str[i]);
		}
	}

	return (num_char_printed);
}
