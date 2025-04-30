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

void *ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	unsigned char	*temp;
		
	if(count == 0 || size == 0)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	temp = (unsigned char *) ptr;
	while (i < (count * size))
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}

void	ft_rev(char *tab, int size)
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
		i++;
		end--;
	}
}

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}	
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
	int		minus;
	long int	nb;
	char		*converted;
	
	i = 0;
	minus = 0;
	nb = (long int) n;

	converted = (char *)ft_calloc((ft_numlen(n) + 1), sizeof(char));
	if (!converted)
		return (NULL);
	if (nb < 0)
	{
		minus = '-';
		nb = -nb;
		i++;
	}
	while (nb != 0)
	{
		converted[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (minus)
	{
		converted[i] = '-';
		i++;
	}
	ft_rev(converted, i);
	return(converted);
}

int	main()
{
	int	num;
	char	*value;
	
	num = -2147483648;
	value = ft_itoa(num);
	if (value != NULL)
	{
		printf("The number: %d\n", num);
		printf("The number converted to ascii: %s\n", value);
		free(value);
	}
	else
	{
		printf("Memory allocation failed.\n");
		free(value);
	}
	return (0);
}

