/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:49:54 by abita             #+#    #+#             */
/*   Updated: 2025/04/26 13:49:58 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	printf("%d\n", ft_strncmp("Arsela", "ArseLa", 6));  // Should be > 0
	printf("%d\n", ft_strncmp("Ar", "Arsela", 2));   // Should be 0
	printf("%d\n", ft_strncmp("Ars", "Arsela", 4));   // Should be < 0
	return (0);
}*/
