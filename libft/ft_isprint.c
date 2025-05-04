/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:01:29 by abita             #+#    #+#             */
/*   Updated: 2025/04/23 11:01:31 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int main()
{
    // Testing printable and non-printable characters
    printf("%d\n", ft_isprint('A'));
    printf("%d\n", ft_isprint('z'));
    printf("%d\n", ft_isprint(' '));
    printf("%d\n", ft_isprint(31));
    printf("%d\n", ft_isprint(127));
    return (0);
}*/
