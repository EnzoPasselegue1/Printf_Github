#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

int ft_printf(const char *format, ...);
int ft_handle_conversion(const char **format, va_list args);

void ft_parse_flags(const char **format, int *width, int *precision, int *left_align, int *zero_pad);
void ft_parse_width_precision(const char **format, int *width, int *precision);
void ft_handle_padding(int width, int len, int left_align, int zero_pad);

int ft_strlen(const char *str);
int ft_ptrlen(uintptr_t ptr);
int ft_numlen_hex(unsigned int num);
int ft_numlen(int n);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnstr(char *str, int n);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_puthex(uintptr_t num, int is_uppercase);
int ft_putptr(uintptr_t ptr);

int ft_handle_char(char c, int width, int left_align, int zero_pad);
int ft_handle_string(char *str, int width, int precision, int left_align);
int ft_handle_int(int num, int width, int left_align, int zero_pad);
int ft_handle_unsigned(unsigned int num, int width, int left_align, int zero_pad);
int ft_handle_pointer(void *ptr, int width, int left_align);
int ft_handle_hex(unsigned int num, int width, int left_align, int zero_pad, int is_uppercase);

#endif