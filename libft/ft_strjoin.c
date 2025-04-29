/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:43:50 by abita             #+#    #+#             */
/*   Updated: 2025/04/29 15:43:54 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	j;
	int	s1_len;
	int	s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));

	if (new_str == NULL) return (NULL);

	i = 0;
	j = 0;
	while (s1[i])
	{
		new_str[j] = s1[i];
		i++;
		j++;	
	}
	i = 0;
	while (s2[i])
	{
		new_str[j] = s2[i];
		i++;
		j++;	
	}
	new_str[j] = '\0';
	return (new_str);
}

int	main()
{
	char	str1[] = "arsela";
	char	str2[] = "bita";
	char	*new_str;

	new_str = ft_strjoin(str1, str2); 
	if (new_str != NULL)
	{
		printf("the 1st string: %s\n", str1);
		printf("the 2nd string: %s\n", str2);
		printf("the concatenated string: %s\n", new_str);
		
		free(new_str);
	}
	else
		printf("The memory allocation failed.");
	return (0);
}
