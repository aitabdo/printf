#include "main.h"
/**
 *print_int - a function that prints integer.
 *@a: int to be printed.
 *Return: int (numbers of ints been printed in a(len(a))).
 */
int print_int(unsigned int a)
{
	int pow = 1, printed_elements = 0;

	while ((a / pow) > 9)
		pow *= 10;

	while (pow > 0)
	{
		printed_elemnts += _putchar('0' + a / pow);
		a %= pow;
		pow /= 10;
	}
	return (printed_elements);
}
