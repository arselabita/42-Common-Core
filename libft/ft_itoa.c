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

void	ft_rev(int *tab, int size)
{
	int	i;
	int	end;
	int	temp;

	end = size - 1;
	i = 0;
	while (i < end)
	{
		temp = tab[i];
		tab[i] = tab[end];
		tab[end] = temp;
		end--;
		i++;
	}
}

int	ft_numlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long int	nb;
	char		*converted;
	
	i = 0;
	nb = (long int) n;
	converted = (char *)malloc((ft_numlen(n) + 1) * sizeof(char));
	if (converted == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		converted[0] = '-';
		i++;
	}
	while (nb != 0)
	{
		converted[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	converted[i] = '\0';
	ft_rev(converted, i);
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

