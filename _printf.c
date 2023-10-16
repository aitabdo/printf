#include "main.h"
/**
 * _printf - A function that prints formats to stdout.
 * @format: string that containes our formats.
 * Return: int (number of characters been printed to stdout.)
 */
int _printf(const char *format, ...)
{
	int num_of_chars = 0;
	va_list arguments;

	if (format == NULL)
		return (-1);
	va_start(arguments, format);
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			num_of_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(arguments, int));
					num_of_chars++;
					break;
				case 's':
					num_of_chars += print_str(va_arg(arguments, char *));
					break;
				case '%':
					_putchar('%');
					num_of_chars++;
					break;
				case '\0':
					break;
				default:
					_putchar(*format);
					num_of_chars += 2;
					break;
			}
		}
		format++;
	}
	va_end(arguments);
	return (num_of_chars);
}
