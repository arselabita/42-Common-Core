/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:22:01 by abita             #+#    #+#             */
/*   Updated: 2025/04/25 22:22:03 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(const char *s, int c)
{
	int		i;
	const char	*temp;
	char	ch = (char)c;

	i = 0;
	temp = 0;
	while (s[i])
	{
		if(s[i] == ch)
			temp = &s[i];
		i++;
	}
	if(ch == '\0')
		return (char *)&s[i];
	return (char *)temp;
}

#include <stdio.h>

int	main()
{
	int	index;
	const char	*value;
	char	s1[20] = "ArselaBiiita";

	printf("String: %s\n", s1);
	value = ft_strrchr(s1, 'i');

	if (value != NULL)
	{
		printf("The char found: %s\n", value);
		index = (int)(value - s1);
		printf("%d\n", index);
	}
	else
		printf("The char is not found.");

	// Test case for the null character '\0'
	value = ft_strrchr(s1, '\0');
	if (value != NULL)
		printf("The null character found at index: %d\n", (int)(value - s1));

	return (0);
}

