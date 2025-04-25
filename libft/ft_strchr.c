/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:51:00 by abita             #+#    #+#             */
/*   Updated: 2025/04/25 11:51:02 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdioi.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if(s[0] == '\0')
		return (s);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (0);
}

int	main()
{
	char	s1[15] = "Arsela Bita";
	char	*value;
	int	c;

	printf("String: %s\n", s1);
	value = ft_strchr(s1, c);
	if (value)
		printf("The char found: %s\n", value);
	else
		printf("The char is not foud.");
	return (0);
}
