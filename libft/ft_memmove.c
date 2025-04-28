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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t		i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	
	i = 0;
	while (d < s)
	{
		i++;
	}
	i = n-1
	while (d > s)
	{
		i--;
	}
/*
	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = temp[i];
		i++;
	}
*/
	return (dest);
}
