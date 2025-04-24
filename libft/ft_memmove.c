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
	unsigned char	buffer[n];
	size_t		i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	
	i = 0;
	while (i < n)
	{
		buffer[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = buffer[i];
		i++;
	}

	return (dest);
}

