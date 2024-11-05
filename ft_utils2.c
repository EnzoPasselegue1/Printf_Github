#include "ft_printf.h"

int ft_ptrlen(uintptr_t ptr)
{
    int len = 0;

    if (ptr == 0)
        return 1;  // Si l'adresse est NULL, on affiche juste '0'
    while (ptr != 0)
    {
        ptr /= 16;  // On divise par 16 pour chaque chiffre hexadécimal
        len++;
    }
    return len;
}

int ft_numlen_hex(unsigned int num)
{
    int len = 0;

    if (num == 0)
        return 1;
    while (num != 0)
    {
        num /= 16;
        len++;
    }
    return len;
}

int ft_putunbr(unsigned int n)
{
    int len = 0;

    if (n > 9)
        len += ft_putunbr(n / 10);
    len += ft_putchar((n % 10) + '0');
    return len;
}