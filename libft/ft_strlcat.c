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

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	end;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	i = 0;
	end = size - 1;
	while (src[i] && (dstlen + i < end))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int main()
{
	char dest[20] = "Hi";
	const char *to_add = ", Arsela!";
	size_t result = ft_strlcat(dest, to_add, sizeof(dest));

	printf("After ft_strlcat: %s\n", dest);
	printf("Returned length: %zu\n", result);

	return (0);
}*/
