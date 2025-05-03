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
#include <stdio.h>
#include <stdlib.h>

int	word_count(char const *s, char c)
{
	int	i;
	int	start;
	int	count;

	i = 0;
	start = 0;
	count = 0;
	while (s[i])
	{	
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
			count++;
	}
	return (count);
}

char	*word_copy(char const *s, int start, int end)
{
	int	i;
	int	j;
	char	*word;

	word = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (word == NULL) return (NULL);

	i = start;
	j = 0;
	while (i < end)
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

void	free_the_split(char **split, int j)
{
	while (j > 0)
	{
		j--;
		free(split[j]);
	}
	free(split);
}

int	save_the_word(char **split, char const *s, int start, int i, int j)
{
	split[j] = word_copy(s, start, i);
	if (!split[j])
	{
		free_the_split(split, j);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	start;
	char	**split;

	if (!(split = (char **)malloc((word_count(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	start = 0;
	while(s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			if (!save_the_word(split, s, start, i, j))
				return (NULL);
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}


int	main()
{
	char	str[] = "Returns NULL if the allocation fails.";
	char	ch = 'a';
	char	**split;
	int	i;

	split = ft_split(str, ch);
	
	if (split != NULL)
	{
		printf("The input: %s\n", str);         
		printf("The delimiter: %c\n", ch);
		i = 0;
		while (split[i])
		{
			printf("split[%d] = %s\n", i, split[i]);
			free(split[i]);
			i++;
		}
		free(split);
	}
	else
	{
		printf("Memory allocation failed.\n");
		free(split);
	}
	return (0);
}                  
