#include "main.h"
#include <stdio.h>

int main(void)
{
    int len;

    len = _printf("Number: %d\n", 123);
    _printf("Length: %d\n", len);

    len = _printf("Negative: %i\n", -456);
    _printf("Length: %d\n", len);

    len = _printf("Binary of %d is %b\n", 98, 98);
    _printf("Length: %d\n", len);

    len = _printf("Unsigned: %u\n", 3000000000U);
    _printf("Length: %d\n", len);

    len = _printf("Octal: %o\n", 12345);
    _printf("Length: %d\n", len);

    len = _printf("Hex lowercase: %x\n", 12345);
    _printf("Length: %d\n", len);

    len = _printf("Hex UPPERCASE: %X\n", 12345);
    _printf("Length: %d\n", len);

    return (0);
}
