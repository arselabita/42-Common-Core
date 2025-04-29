/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:55:43 by abita             #+#    #+#             */
/*   Updated: 2025/04/29 10:55:44 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
//#include "libft.h"


/*
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return (char*)(big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && (i + j) < len)
			j++;
		if (!little[j])
			return (char*)(&big[i]);
		i++;
	}
	return (0);
}*/

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length_of_s;
	char	*sub;

	if (s == NULL)
		return (NULL);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	length_of_s = ft_strlen(s);
	if (start > length_of_s)
		return (NULL);
	if ((start + len) > length_of_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

int	main()
{
	char	str[] = "The substring starts at index ’start’.";
	char	*substr;
	
	substr = ft_substr(str, 5, 9);
	if (substr != NULL)
	{
		printf("The string: %s\n", str);
		printf("The sub-string: %s\n", substr);
		free(substr);
	}
	else
		printf("Failed to allocate memory.\n");
	return (0);
}
