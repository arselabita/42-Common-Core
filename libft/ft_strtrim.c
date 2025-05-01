/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:15:04 by abita             #+#    #+#             */
/*   Updated: 2025/04/29 17:15:07 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	ch = (char)c;

	i = 0;
	if(ch == '\0')
		return (char *)&s[i];
	while (s[i])
	{
		if(s[i] == ch) return (char *)&s[i];
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	start;
	int	end;
	int	length;
	int	i;
	
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	length = end - start + 1;
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL) return (NULL);

	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	char	str[] = "ter array must end with a NULL pointer";
	char	rem_chr[] = "ter";
	char	*trimed_str;

	trimed_str = ft_strtrim(str, rem_chr);
	if (trimed_str != NULL)
	{
		printf("The string: \n%s\n", str);
		printf("\n");
		printf("Trimed string excluding %s: \n%s\n", rem_chr, trimed_str);

		free(trimed_str);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}*/
