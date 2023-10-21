#include "main.h"

/**
 * _printf - function that prints anything.
 * @format: list of arguments passed to the function.
 * Return: int (number of chars printed).
 */
int _printf(const char *format, ...)
{
	int num_char_printed = 0;
	form_spec specifiers[] = {
		{"s", print_str},
		{"c", print_char},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_bin},
		{"r", print_rev},
		{"R", print_rot13},
		{"S", print_STR},
		{"p", print_addr},
		{"o", print_oct},
		{"u", print_unsigned},
		{"X", print_HEX},
		{"x", print_hex},
		{NULL, NULL}
	};
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	num_char_printed = _print(format, specifiers, args);
	va_end(args);

	return (num_char_printed);
}
/**
 * _print - prints anything.
 * @format: list of arguments passed to the function.
 * @specifiers: list of our specifiers.
 * @args: list of arguments
 * Return: int (number of chars printed).
 */
int _print(const char *format, form_spec specifiers[], va_list args)
{
	int num_char_printed = 0, i = 0, j;
	int k;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			for (j = 0; specifiers[j].c != NULL; j++)
			{
				if (format[i] == specifiers[j].c[0])
				{
					k = specifiers[j].f(args);
					if (k == -1)
						return (-1);
					num_char_printed += k;
					break;
				}
			}
			if (specifiers[j].c == NULL)
			{
				num_char_printed += print_percent(args);
				num_char_printed += _putchar(format[i]);
			}
		}
		else
		{
			num_char_printed += _putchar(format[i]);
		}
		i++;
	}
	return (num_char_printed);
}
