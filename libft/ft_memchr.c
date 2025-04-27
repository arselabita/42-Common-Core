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

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t len)
{
	size_t i;
	unsigned char *ptr;
	
	i = 0;
	ptr = (unsigned char *)str;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

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
			return (void*)&str[i];
		i++;
	}
	return (0);
}

int	main()
{
	int	index;
	char	str[10000];
	char	*value;
	char	*str_memset;
	printf("The input: %s\n", str);
	str_memset = ft_memset(str, 0, sizeof(str));
	value = ft_memchr(str, 3, sizeof(str));
	
	if (value != NULL)
	{
		printf("The char found: %s\n", value);
		index = (int)(value - str);
		printf("%d\n", index);
	}
	else
		printf("The char is not found.");

	return (0);
}

