/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:44:09 by abita             #+#    #+#             */
/*   Updated: 2025/04/24 21:44:11 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	
	if (cpy_dst == size)
		return (size + cpy_src);
	if (dstlen < size - dstlen)
		return ();


/////////////////////////////////////////////
	if (dst[j] < size)
	{
		while (src[i])
		{
			dst[j + i] = src[i];
			i++;
		}
	}
	length = i + j;
	if (dst[j] == size)
		return (length);

	dst[i + j] = '\0';
	return(length);
}
//////////////////////////////////////////
int	main()
{
	char	src[10] = "arsela";
	char	dest[10] = "bita";
	size_t	size = 8;

	printf("After: %zu\n", ft_strlcat(dest, src, size));
}

