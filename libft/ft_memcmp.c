/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:34:56 by abita             #+#    #+#             */
/*   Updated: 2025/04/27 16:34:58 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t		i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i]  - str2[i]);
		i++;
	}
	
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}
