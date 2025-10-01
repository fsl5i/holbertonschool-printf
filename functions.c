#include "main.h"

/**
 * print_char - prints a single character
 * @c: character to print
 * Return: 1 on success, -1 on error
 */
int print_char(char c)
{
    if (write(1, &c, 1) != 1)
        return (-1);
    return (1);
}

/**
 * print_string - prints a string
 * @s: string to print
 * Return: number of characters printed, -1 on error
 */
int print_string(const char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
    {
        if (write(1, s, 1) != 1)
            return (-1);
        count++;
        s++;
    }
    return (count);
}

/**
 * print_number - prints an integer
 * @n: number to print
 * Return: number of characters printed
 */
int print_number(int n)
{
    int count = 0;
    char c;

    if (n < 0)
    {
        if (write(1, "-", 1) != 1)
            return (-1);
        count++;
        n = -n;
    }
    if (n >= 10)
        count += print_number(n / 10);

    c = (n % 10) + '0';
    if (write(1, &c, 1) != 1)
        return (-1);
    count++;

    return (count);
}

/**
 * handle_specifier - selects which print function to use
 * @ap: pointer to the argument list
 * @sp: specifier character
 * Return: number of characters printed, -1 on error
 */
int handle_specifier(va_list *ap, char sp)
{
    if (sp == 'c')
        return print_char((char)va_arg(*ap, int));
    if (sp == 's')
        return print_string(va_arg(*ap, char *));
    if (sp == 'd' || sp == 'i')
        return print_number(va_arg(*ap, int));
    if (sp == '%')
        return print_char('%');

    return (0); /* unknown specifier, ignore */
}

/**
 * _printf - simplified printf function
 * @format: format string
 * Return: number of characters printed, -1 on error
 */
int _printf(const char *format, ...)
{
    va_list ap;
    int total = 0, r;
    int i = 0;

    if (!format)
        return (-1);

    va_start(ap, format);

    while (format[i])
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
