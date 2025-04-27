/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:16:04 by abita             #+#    #+#             */
/*   Updated: 2025/04/27 17:16:09 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return (big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && (i + j) < len)
			j++;
		if (!little[j])
			return (&big[i]);
		i++;
	}
	return (0);
}

int	main()
{
	char	big[] = "The following sets the pointer ptr to NULL";
	char	little[] = "NULL";
	char	*value;

	value = ft_strnstr(big, little, sizeof(big));

	if (value)
		printf("The string found is: %s\n", value);
	else
		printf("The string is not found.");
	
	return (0);
}
