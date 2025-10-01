#include <unistd.h>
#include "main.h"
/**
* print_int - prints an integer to stdout
* @n: the integer to print
* Return: printed numbers
*/

int print_int(int n)

{

	int count = 0;
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}

        if (n >= 10)â
		count += print_int(n / 10);

	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;

	return count;
}
