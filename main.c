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
    
return (0);
}
