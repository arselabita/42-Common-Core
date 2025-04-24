/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:34:09 by abita             #+#    #+#             */
/*   Updated: 2025/04/24 11:34:11 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	end;
	unsigned int	length;

	end = size - 1;
	length = 0;
	while (src[length])
		length++;
	if (size == 0)
		return (length);
	i = 0;
	while (src[i] && i < end)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}

int	main()
{
	char arr[] = "Arsela Bita";
	char dest[50];
	unsigned int size = 50; 
	
	
	printf("Before: %s\n", arr);
	
	printf("After: %d\n", ft_strlcpy(dest, arr, size));
	return 0;
}
