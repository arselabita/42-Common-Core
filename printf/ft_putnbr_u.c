#include "libftprintf.h"

int ft_putnbr_u(unsigned int nb)
{
    unsigned int    length;

    length = 0;
    if (nb == 0)
        return (ft_putchar('0'));
    if (nb >= 10)
        length += ft_putnbr_u(nb / 10);
    length += ft_putchar((nb % 10) + '0');
    return (length);
}
    