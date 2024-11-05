#include "ft_printf.h"

int ft_handle_string(char *str, int width, int precision, int left_align)
{
    int len = str ? ft_strlen(str) : 6;

    if (precision >= 0 && precision < len)
        len = precision;
    if (!left_align && width > len)
        ft_handle_padding(width, len, left_align, 0);
    len = ft_putnstr(str, len);
    if (left_align && width > len)
        ft_handle_padding(width, len, left_align, 0);
    return len;
}

int ft_handle_pointer(void *ptr, int width, int left_align)
{
    int len = ft_ptrlen((uintptr_t)ptr);

    if (!left_align && width > len)
        ft_handle_padding(width, len, left_align, 0);
    len = ft_putptr((uintptr_t)ptr);
    if (left_align && width > len)
        ft_handle_padding(width, len, left_align, 0);
    return len;
}

int ft_putptr(uintptr_t ptr)
{
    int len = 0;

    len += ft_putstr("0x");
    len += ft_puthex(ptr, 0);
    return len;
}

int ft_puthex(uintptr_t num, int is_uppercase)
{
    char *base;
    int len = 0;

    base = is_uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    if (num >= 16)
        len += ft_puthex(num / 16, is_uppercase);
    len += ft_putchar(base[num % 16]);
    return len;
}