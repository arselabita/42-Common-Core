
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_numlen(int *number)
{
	int	i;
	int	minus;

	i = 0;
	minus = 1;
	while (number[i] == '+' || number[i] == '-')
	{
		if (number[i] == '-')
			minus = -1;
		i++;
	}
	while (number[i])
		i++;
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
	int		i;
	unsigned char	*converted;

	converted = (unsigned char *)malloc((ft_numlen(n) + 1) * sizeof(unsigned char));
	if (converted == NULL)
		return (NULL);
	if (num == 0)
		return ('0\0');
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