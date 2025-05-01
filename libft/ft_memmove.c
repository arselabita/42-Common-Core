/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:17:52 by abita             #+#    #+#             */
/*   Updated: 2025/04/24 09:17:54 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t		i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;

	if (d == s || n == 0)
		return (dest);
	i = 0;
	if (d < s)
	{
		while (i < n)
			d[i] = s[i];
			i++;
	}
	else
	{
		while (n > 0)
		{
			d[n] = s[i];
			n--;
		}
	}
	return (dest);
}
