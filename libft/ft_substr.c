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

#include <stdio.h>

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
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	
}

int	main()
{
	char	str[] = "The substring starts at index ’start’..";
	char	*substr;
	
	substr = ft_substr(str, 5, sizeof(str));
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
