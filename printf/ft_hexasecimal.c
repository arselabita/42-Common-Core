#include "libftprintf.h"

int ft_hexasecimal(unsigned long nb)
{
    char    *base;
    char    buffer[20];
    int     i;
    unsigned long length;

    length = 0;
    base = "0123456789abcdef";
    if (nb == 0)
        return ft_putchar('0');
    i = 0;
    // ndarja e nurit dhe e ruaj ate ne buffer 
    while (nb > 0)
    {
        buffer[i++] = base[nb % 16];
        nb /= 16;
    }
    // i printoj shifrat nga fundi ne fillim
    i--;
    while (i >= 0)
    {
        length += ft_putchar(buffer[i]);
        i--;
    }
    return (length);
}