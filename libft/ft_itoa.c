/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:03:57 by abita             #+#    #+#             */
/*   Updated: 2025/04/30 13:04:08 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		if (n < 0)
			n = -n;
		i++;
		return (ft_numlen(n/10));
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long int	nb;
	char		*converted;

	converted = (char *)malloc((ft_numlen(n) + 1) * sizeof(char));
	if (converted == NULL)
		return (NULL);
	if (n == 0)
		converted[0] = '0';
		converted[1] = '\0';
	nb = n;
	if (nb < 0)
		nb = -nb;
	i = 0;
	while(nb != 0)
	{
		if (nb >= 10)
			nb /= 10;
		converted[i] = (nb % 10) + '0';
		i++;
	}
	converted[i] = '\0';
	return(converted);
}

int	main()
{
	int	num;
	char	*value;

	num = 42;
	value = ft_itoa(num);
	if (value != NULL)
	{
		printf("The number: %d\n", num);
		printf("The number converted to ascii: %s\n", value);
		free(value);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}

