#include "ft_printf.h"

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int ft_putstr(char *str)
{
    int len = 0;

    if (!str)
        str = "(null)";
    while (*str)
        len += ft_putchar(*str++);
    return len;
}

int ft_putnstr(char *str, int n)
{
    int len = 0;

    if (!str)
        return ft_putstr("(null)");
    while (*str && n-- > 0)
        len += ft_putchar(*str++);
    return len;
}

int ft_numlen(int n)
{
    int len = 0;

    if (n <= 0)  // Si n est négatif ou nul, on compte le signe
        len = 1;
    while (n != 0)
    {
        n /= 10;  // On divise par 10 jusqu'à ce que n devienne 0
        len++;
    }
    return len;
}

int ft_strlen(const char *str)3
{
    int len = 0;

    while (str[len])
        len++;
    return len;
}