#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - prints one char
 * @c: character
 * Return: 1 on success, -1 on error
 */
int print_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

/**
 * print_string - prints a string (NULL -> "(null)")
 * @s: string
 * Return: chars printed, -1 on error
 */
int print_string(const char *s)
{
	int n = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		if (write(1, s, 1) != 1)
			return (-1);
		n++;
		s++;
	}
	return (n);
}

/**
 * print_int - prints an integer
 * @n: integer to print
 * Return: number of characters printed
 */
int print_int(int n)
{
	int count = 0;
	char buf[12];
	int i = 0, j;

	if (n == 0)
		return (print_char('0'));

	if (n < 0)
	{
		if (print_char('-') == -1)
			return (-1);
		count++;
		if (n == -2147483648) /* INT_MIN */
		{
			if (print_string("2147483648") == -1)
				return (-1);
			return (count + 10);
		}
		n = -n;
	}

	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (print_char(buf[j]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

/**
 * handle_specifier - handles %c, %s, %d, %i, %%
 * @ap: va_list pointer
 * @sp: specifier
 * Return: chars printed, -1 on error
 */
int handle_specifier(va_list *ap, char sp)
{
	if (sp == 'c')
		return (print_char((char)va_arg(*ap, int)));
	if (sp == 's')
		return (print_string(va_arg(*ap, char *)));
	if (sp == 'd' || sp == 'i')
		return (print_int(va_arg(*ap, int)));
	if (sp == '%')
		return (print_char('%'));
        if (sp == 'b')
              return (print_binary(va_arg(*ap, unsigned int)));
	
	/* unknown specifier */
	if (print_char('%') == -1 || print_char(sp) == -1)
		return (-1);
	return (2);
}

/**
 * _printf - simplified printf
 * @format: format string
 * Return: number of printed chars, -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, total = 0, r;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			if (print_char(format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			total++;
			i++;
			continue;
		}
		i++;
		if (format[i] == '\0')
			return (-1);
		r = handle_specifier(&ap, format[i]);
		if (r == -1)
		{
			va_end(ap);
			return (-1);
		}
		total += r;
		i++;
	}
	va_end(ap);
	return (total);
}
