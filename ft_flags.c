#include "ft_printf.h"

void ft_parse_flags(const char **format, int *width, int *precision, int *left_align, int *zero_pad)
{
    *left_align = 0;
    *zero_pad = 0;
    *width = 0;
    *precision = -1;

    while (**format == '-' || **format == '0')
    {
        if (**format == '-')
            *left_align = 1;
        if (**format == '0')
            *zero_pad = 1;
        (*format)++;
    }
    ft_parse_width_precision(format, width, precision);
}

void ft_parse_width_precision(const char **format, int *width, int *precision)
{
    while (**format >= '0' && **format <= '9')
    {
        *width = *width * 10 + (**format - '0');
        (*format)++;
    }
    if (**format == '.')
    {
        (*format)++;
        *precision = 0;
        while (**format >= '0' && **format <= '9')
        {
            *precision = *precision * 10 + (**format - '0');
            (*format)++;
        }
    }
}

void ft_handle_padding(int width, int len, int left_align, int zero_pad)
{
    if (left_align)
        return;

    char pad_char = zero_pad;
    
    if (zero_pad)
    pad_char = '0';
    else
    pad_char = ' ';
    while (width-- > len)
        ft_putchar(pad_char);
}
