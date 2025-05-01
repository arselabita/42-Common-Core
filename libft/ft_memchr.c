/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:07:43 by abita             #+#    #+#             */
/*   Updated: 2025/04/27 12:07:48 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	unsigned char	ch;
	unsigned char	*str;

	ch = (unsigned char) c;
	str = (unsigned char *)s;

	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return &str[i];
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	int	index;
	char	str[10000] = "abita";
	char	*value;
	printf("The input: %s\n", str);
	value = ft_memchr(str, 't', sizeof(str));
	
	if (value != NULL)
	{
		printf("The char found: %s\n", value);
		index = (int)(value - str);
		printf("the index: %d\n", index);
	}
	else
		printf("The char is not found.");

	return (0);
}*/

