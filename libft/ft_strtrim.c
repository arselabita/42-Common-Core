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

char *ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	char	*str;
	
	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL) return (NULL);

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				
			}	
			j++;
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}

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
}
