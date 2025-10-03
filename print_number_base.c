#include "main.h"

/**
 * print_number_base - prints an unsigned int in a given base
 * @n: the number to print
 * @base: the base (e.g. 10 for decimal, 8 for octal, 16 for hex)
 * @uppercase: 0 = lowercase letters, 1 = uppercase letters
 * Return: number of characters printed
 */
int print_number_base(unsigned int n, int base, int uppercase)
{
char digits[] = "0123456789abcdef";
char digits_upper[] = "0123456789ABCDEF";
char buffer[32];
int i = 0, count = 0;
char *set;

set = (uppercase ? digits_upper : digits);

if (n == 0)
return (print_char('0'));

while (n > 0)
{
buffer[i++] = set[n % base];
n /= base;
}

while (i--)
count += print_char(buffer[i]);

return (count);
}
