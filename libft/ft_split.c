/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:48:25 by abita             #+#    #+#             */
/*   Updated: 2025/05/01 15:48:28 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int	i;
	char	**split;

	split = (char **)malloc(ft(ft_strlen(s)) * sizeof(char *));
	if (split == NULL) return (NULL);

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (split);
}

int	main()
{
	char	str[] = "Returns NULL if the allocation fails.";
	char	ch = 'a';
	char	**split;

	split = ft_split(str, ch);
	
	//maybe free the allocated memory properly (loop)
	if (split != NULL)
	{
		printf("The input: %s\n", str);         
		printf("The delimiter: %c\n", ch);
		printf("The output: %s\n", split);
		free(split);
	}
	else
	{
		printf("Memory allocation failed.\n");
		free(split);
	}
	return (0);
}                  
