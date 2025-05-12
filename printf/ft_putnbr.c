#include "libftprintf.h"

int ft_putnbr(int nb)
{
    long int length;
    long int n;
    
    length = 0;
    n = nb;
    if (n < 0)
    {
        length += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        length += ft_putnbr(n / 10);
    length += ft_putchar((n % 10) + '0');
    return (length);
}
