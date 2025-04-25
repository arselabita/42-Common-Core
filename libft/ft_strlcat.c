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
	size_t	length;
	size_t j;
	size_t i;
	
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);

	i = 0;
	length = dstlen + srclen;	
	while (src[i] && dstlen + i < size - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return(length);
}

int	main()
{
	char	src[] = "arsecdekkkkkkkkkkkf";
	char	dest[12] = "bita";
	
	size_t a = ft_strlcat(dest, src, sizeof(dest));
	printf("%s\n", dest);
	printf("%zu\n", a);
	
	return 0;
}

