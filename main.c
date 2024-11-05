#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, World!\n");
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "42");
    ft_printf("Integer: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);

    return 0;
}