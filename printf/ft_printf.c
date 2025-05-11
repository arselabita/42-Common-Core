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

int printf(const char* format, ...)
{
    va_list args;
    char    buffer[20];
    int     size;
    int     i;
    int     j;

    va_start(args, format);

    //ketu iteroj ne te gjithe format stringun qe do te shfaqet ne console
    i = 0;
    j = 0;
    while (format[i] && i < size - 1)
    {
        //kusht nese ne hasim nje % 
        if (ft_strchr(format, '%'))
            i++;
        // duhet te vendos cdo element ne output format.
        buffer[j++] = format[i++];
    }
    buffer[j] = '\0';
    return (buffer);
}
int main()
{
    ft_printf("Hi, I'm %s", "Arsela");
    return (0);
}