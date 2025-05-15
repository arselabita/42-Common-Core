#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int ft_hexadecimal_upper(unsigned long nb);
int ft_hexadecimal(unsigned long nb);
int ft_putnbr_u(unsigned int nb);
int	ft_putstr(char *str);
int ft_putnbr(int nb);
int ft_putchar(char c);

#endif