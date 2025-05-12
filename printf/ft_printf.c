/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:14:07 by abita             #+#    #+#             */
/*   Updated: 2025/05/09 12:14:07 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
    return (i);
}

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

int ft_hexasecimal_upper(unsigned long nb)
{
    char    *base;
    char    buffer[20];
    int     i;
    unsigned int    length;

    length = 0;
    base = "0123456789ABCDEF";
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
        
static int format_specifiers (char *format, int i, va_list args)
{
    int length;

    length = 0;
    // konverto ne decimal ose int
    if (format[i] == 'd' || format[i] == 'i')
        return (ft_putnbr(va_arg(args, int)));
    // konverto ne char
    else if (format[i] == 'c')
        return (ft_putchar(va_arg(args, int)));
    // konverto ne string
    else if (format[i] == 's')
        return (ft_putstr(va_arg(args, char *)));
    // konverto ne pointer print adresen
    else if (format[i] == 'p')
    {
        length += ft_putstr("0x");
        length += ft_hexasecimal(va_arg(args, unsigned long));
        return (length);
    }
    // konverto ne unsigned int
    else if (format[i] == 'u')
       return  (ft_putnbr_u((va_arg(args, unsigned int))));
    // konverto ne hex base sys lowercase
    else if (format[i] == 'x')
       return (ft_hexasecimal(va_arg(args, unsigned long)));
    // konverto ne hex base sys uppercase
    else if (format[i] == 'X')
        return (ft_hexasecimal_upper(va_arg(args, unsigned long)));
    // printo % sign
    else if (format[i] == '%')
        return (ft_putchar('%'));
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int length;
    int i;

    va_start(args, format);

    i = 0;
    length = 0;
    // ketu iteroj ne te gjithe format stringun qe do te shfaqet ne console
    while (format[i])
    {
        // kusht nese ne hasim nje %
        if (format[i] == '%')
        {
            i++;
            // therras funksionin per te format specifiers
            length += format_specifiers((char *)format, i, args);
        }
        // ne te kunder thjesht printo str ne console
        else
            length += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (length);
}

int main()
{
    char str[] = "arsela";
    int num;
    int i;

    num = 21;
    i = ft_printf("mine: %s\n", str);
    printf("mine: %d\n", i);
    i = printf("theirs: %s\n", str);
    printf("theirs: %d\n", i);
    printf("\n");

    // per te printuar numer base 10 d dhe i
    ft_printf("d dhe i: im a number %d and me too %i\n", num, num);
    printf("real d dhe i: im a number %d and me too %i\n", num, num);
    printf("\n");
    // per te printuar nje karakter
    ft_printf("c: my first letter is: %c\n", 'A');
    printf("real c: my first letter is: %c\n", 'A');
    printf("\n");
    // per te printuar nje string
    ft_printf("s: my name is: %s\n", "Arsela");
    printf("reals: my name is: %s\n", "Arsela");
    printf("\n");
    // per te printuar adresen e diff ptr
    ft_printf("p: %p\n", &num);
    printf("real p: %p\n", &num);
    printf("\n");
    // per te printuar positive num unsif=gned int-s
    num = 194967295;
    ft_printf("u: %u\n", num);
    printf("real u: %u\n", num);
    printf("\n"); 
    // per te printuar hexadec num lowercase
    ft_printf("x: %x\n", 255);
    printf("real x: %x\n", 255);
    printf("\n");
    // per te printuar hexadec num uppercase
    ft_printf("X: %X\n", 255);
    printf("real X: %X\n", 255);
    printf("\n");
    // per te printuar %
    ft_printf("%%: %%\n");
    printf("real %%: %%\n");
    printf("\n");

    return (0);
}