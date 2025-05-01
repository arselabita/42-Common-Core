/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:35:52 by abita             #+#    #+#             */
/*   Updated: 2025/04/25 11:35:56 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
int	main()
{
	int 	i;
	char	letter;
	char	letters[20] = "ARSE';LA";

	ft_tolower('A');
	
	i = 0;
	while (letters[i])
	{
		printf("%c", ft_tolower(letters[i]));
		i++;
	}
	return (0);
}*/
