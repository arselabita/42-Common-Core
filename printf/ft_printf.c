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
    // konverto ne pointer
   /* else if (format[i] == 'p')
    {
    }
    else if (format[i] == 'u')
    {
    }
    else if (format[i] == 'x')
    {
    }
    else if (format[i] == 'X')
    {
    }*/
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
            // therras funksionin per format specifiers
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
    ft_printf("Hi, I'm %s, im %d yo, my bday is on %i august, surname %c.\n", "Arsela", 21, 14, 'B');
    return (0);
}