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

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}
static void	ft_putnbr(int nb)
{
	char	    print;
	long int	n;
	
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

int ft_printf(const char* format, ...)
{
    va_list args;
    int     next_arg;
    int     i;
    int     j;

    va_start(args, format);
    //ketu iteroj ne te gjithe format stringun qe do te shfaqet ne console
    i = 0;
    j = 0;
    next_arg = 0;
    while (format[i] && i < ft_strlen(format) - 1)
    {
        //kusht nese ne hasim nje % 
        if (format[i] == '%')
            i++;
            // konverto ne decimal ose int
            if (format[i + 1] == 'd' || format[i + 1] == 'i')
            {
                next_arg = va_arg(args, int);
                ft_putnbr(next_arg);
            }
            // konverto ne char
            else if (format[i + 1] == 'c')
            {
                next_arg = va_arg(args, int);            
                ft_putchar(next_arg);    
            }
            // konverto ne string
            else if (format[i + 1] == 's')
            {
                next_arg = va_arg(args, char *);            
                ft_putchar(next_arg);
            }
            else if (format[i + 1] == 'p')
            {
                next_arg = va_arg(args, char *);            
                ft_putchar(next_arg);
            }
            else if (format[i + 1] == 'u')
            {

            }
            else if (format[i + 1] == 'x')
            {

            }
            else if (format[i + 1] == 'X')
            {

            }
            else if (format[i + 1] == '%')
            {

            }
            else
            {
                ft_putchar(format[i]);
            }
            va_end(args);
            i++;
    }
    return (next_arg);
}
int main()
{
    ft_printf("Hi, I'm %s", "Arsela");
    return (0);
}