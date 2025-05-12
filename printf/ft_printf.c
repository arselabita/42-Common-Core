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

int ft_printf(const char* format, ...)
{
    va_list args;
    int next_arg;
    char    buffer[20];
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
            if (format[i] == 'd' || format[i] == 'i')
                next_arg = ft_itoa(va_arg(args, int));
            else if (format[i] == 'c')
            {

            }
            else if (format[i] == 's')
            {

            }
            else if (format[i] == 'p')
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

            }
            else
            
            va_end(args);
            i++;
        // duhet te vendos cdo element ne output format.
        buffer[j++] = format[i++];
    }
    buffer[j] = '\0';
    return (next_arg);
}
int main()
{
    ft_printf("Hi, I'm %s", "Arsela");
    return (0);
}