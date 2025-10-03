#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @n: number to print
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
int count = 0;
char buf[32];
int i = 0, j;

if (n == 0)
return (print_char('0'));

while (n > 0)
{
buf[i++] = (n % 2) + '0';
n /= 2;
}

for (j = i - 1; j >= 0; j--)
{
if (print_char(buf[j]) == -1)
return (-1);
count++;
}
return (count);
}
