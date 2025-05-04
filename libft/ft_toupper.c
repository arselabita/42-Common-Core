/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:13:28 by abita             #+#    #+#             */
/*   Updated: 2025/04/25 11:13:34 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
int main()
{
    printf("%c\n", ft_toupper('a'));
    printf("%c\n", ft_toupper('z'));
    printf("%c\n", ft_toupper('A'));
    printf("%c\n", ft_toupper('Z'));
    printf("%c\n", ft_toupper('1'));
    printf("%c\n", ft_toupper('#'));
    return (0);
}*/
