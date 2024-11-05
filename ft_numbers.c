#include "ft_printf.h"

int ft_handle_int(int num, int width, int left_align, int zero_pad)
{
    int len = ft_numlen(num);

    if (!left_align && width > len)
        ft_handle_padding(width, len, left_align, zero_pad);
    len = ft_putnbr(num);
    if (left_align && width > len)
        ft_handle_padding(width, len, left_align, zero_pad);
    return len;
}

int ft_handle_unsigned(unsigned int num, int width, int left_align, int zero_pad)
{
    int len = ft_numlen(num);

    if (!left_align && width > len)
        ft_handle_padding(width, len, left_align, zero_pad);
    len = ft_putunbr(num);
    if (left_align && width > len)
        ft_handle_padding(width, len, left_align, zero_pad);
    return len;
}

int ft_putnbr(int n)
{
    int len = 0;

    if (n == -2147483648)
        return ft_putstr("-2147483648");
    if (n < 0)
    {
        len += ft_putchar('-');
        n = -n;
    }
    if (n > 9)
        len += ft_putnbr(n / 10);
    len += ft_putchar((n % 10) + '0');
    return len;
}

int ft_handle_hex(unsigned int num, int width, int left_align, int zero_pad, int is_uppercase)
{
    int len = ft_numlen_hex(num);  // On calcule la longueur du nombre en hexadécimal

    if (!left_align && width > len)
        ft_handle_padding(width, len, left_align, zero_pad);
    len = ft_puthex(num, is_uppercase);  // On affiche le nombre en hexadécimal
    if (left_align && width > len)
        ft_handle_padding(width, len, left_align, zero_pad);
    return len;
}

int ft_handle_char(char c, int width, int left_align, int zero_pad)
{
    int len = 1;  // Un caractère a toujours une longueur de 1

    if (!left_align && width > len)  // Ajoute du padding avant le caractère si non aligné à gauche
        ft_handle_padding(width, len, left_align, zero_pad);
    
    ft_putchar(c);  // Affiche le caractère
    
    if (left_align && width > len)  // Ajoute du padding après le caractère si aligné à gauche
        ft_handle_padding(width, len, left_align, zero_pad);
    
    return (width > len) ? width : len;  // Retourne la largeur réelle imprimée
}
