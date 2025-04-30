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
	if (n > 0)
	{
		i += 1;
		return (ft_numlen(n/10));
	}
	else
		return (i);
}

void	ft_putnbr(int nb)
{
	char	print;
	long int	n;
	
	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	print = (n % 10) + '0';
	write(1, &print, 1);
}

char	*ft_itoa(int n)
{
	char		*converted;
	char		print;
	int		i;
	long int	nb;
	

	converted = (char *)malloc((ft_numlen(n) + 1) * sizeof(char));
	if (converted == NULL)
		return (NULL);
	if (n == 0)
		converted[i] = '\0';
	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	print = (n % 10) + '0';
	write(1, &print, 1);
	i = 0;
	while(converted[i] >= 48 && converted[i] <= 57)
	{
		ft_putnbr(converted);
	}

	converted[i] = '\0';
	return(converted);
}

int	main()
{
	int	num;
	char	*value;

	value = ft_itoa(9);
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

