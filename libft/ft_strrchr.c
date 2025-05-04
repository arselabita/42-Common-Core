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

#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		ch;
	const char	*last_ch;

	ch = (char)c;
	i = 0;
	last_ch = NULL;
	while (s[i])
	{
		if (s[i] == ch)
			last_ch = &s[i];
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return ((char *)last_ch);
}
/*
int	main()
{
	const char *str = "This is 42 Vienna!";
	char *value = ft_strrchr(str, '4');

	if (value)
		printf("Last '4' found at: %s\n", value);
	else
		printf("Character not found\n");

	return (0);
}*/
