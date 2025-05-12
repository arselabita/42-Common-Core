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

static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void ft_putnbr(int nb)
{
    char print;
    long int n;

    n = nb;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    print = (n % 10) + '0';
    write(1, &print, 1);
}

static void ft_hexasecimal_lower(unsigned int nb)
{
    char    *base;
    char    *buffer;
    int     i;

    base = "0123456789abcdef";
    if (nb == '0')
        write(1, "0", 1);
    i = 0;
    // ndarja e nurit dhe e ruaj ate ne buffer 
    while (nb > 0)
    {
        buffer[i++] = base[nb % 16];
        nb /= 16;
    }
    // i printoj shifrat nga fundi ne fillim 
    while (i >= 0)
    {
        write(1, &buffer[i], 1);
        i--;
    }
}

static void ft_hexasecimal_upper(unsigned int nb)
{
    char    *base;
    char    *buffer;
    int     i;

    base = "0123456789ABCDEF";
    if (nb == '0')
        write(1, "0", 1);
    i = 0;
    // ndarja e nurit dhe e ruaj ate ne buffer 
    while (nb > 0)
    {
        buffer[i++] = base[nb % 16];
        nb /= 16;
    }
    // i printoj shifrat nga fundi ne fillim 
    while (i >= 0)
    {
        write(1, &buffer[i], 1);
        i--;
    }
}
        
static int format_specifiers (char *format, int i, va_list args)
{
    // konverto ne decimal ose int
    if (format[i] == 'd' || format[i] == 'i')
        ft_putnbr(va_arg(args, int));
    // konverto ne char
    else if (format[i] == 'c')
        ft_putchar(va_arg(args, int));
    // konverto ne string
    else if (format[i] == 's')
        ft_putstr(va_arg(args, char *));
    // konverto ne pointer print adresen
    else if (format[i] == 'p')
    {
        ft_putstr("Ox");
        ft_hexasecimal_lower(va_arg(args, unsigned long long));
    }
    /*else if (format[i] == 'u')
    {

    }*/
    else if (format[i] == 'x')
    {
        ft_hexasecimal_lower(va_arg(args, unsigned int));
    }
    else if (format[i] == 'X')
    {
        ft_hexasecimal_upper(va_arg(args, unsigned int));
    }
    else if (format[i] == '%')
        ft_putchar('%');
    return (1);
}
int ft_printf(const char *format, ...)
{
    va_list args;
    int i;

    va_start(args, format);

    i = 0;
    // ketu iteroj ne te gjithe format stringun qe do te shfaqet ne console
    while (format[i])
    {
        // kusht nese ne hasim nje %
        if (format[i] == '%')
        {
            i++;
            // therras funksionin per te format specifiers
            format_specifiers((char *)format, i, args);
        }
        else
            ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (0);
}

int main()
{
    int num;
    int *ptr;
    int ptr = &num;
    
    num = 21;
    // per te printuar numer base 10 d dhe i
    ft_printf("im a number %d and me too %i\n", num, num);
    // per te printuar nje karakter
    ft_printf("my first letter is: %c\n", 'A');
    // per te printuar nje string
    ft_printf("my name is: %s\n", "Arsela");
    // per te printuar adresen e diff ptr
    ft_printf("%p\n", (void *)&ptr);
    // per te printuar hexadec num lowercase
    ft_printf("%x\n", 255);
    // per te printuar hexadec num uppercase
    ft_printf("%X\n", 255);
    // per te printuar %
    ft_printf("%%\n");


    //test 
    ft_printf("Hi, I'm %s, im %d yo, my bday is on %i august, surname %c.\n", "Arsela", num, 14, 'B');
    

    return (0);
}