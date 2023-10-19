#include "main.h"
/**
 * _printf - A function that prints formats to stdout.
 * @format: string that containes our formats.
 * Return: int (number of characters been printed to stdout.)
 */
int _printf(const char *format, ...)
{
	int printed_elements = 0, i;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (0);
	va_start(args, format);
	for (i = 0 ; format[i] ; i++)
	{
		if (format[i] != '%')
		{
			printed_elements += _putchar(format[i]);
		}
		else
		{
			i++;
			if (format[i] == 's')
			{
				printed_elements += print_string(va_arg(args, char *));
			}
			else if (format[i] == 'c')
			{
				printed_elements += _putchar(va_arg(args, int));
			}
			else if (format[i] == 'i')
			{
				printed_elements += print_int(va_arg(args, unsigned int));
			}
			else if (format[i] == '%')
			{
				printed_elements += print_char('%');
			}
			else
			{
				printed_elements += _putchar(format[i]);
			}
		}
	}
	va_end(args);
	return (printed_elements);
}
