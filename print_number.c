#include <unistd.h>

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;

	char c;


	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}

	if (n >= 10)
		count += print_number(n / 10);

	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;

	return (count);
}
