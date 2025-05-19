#include "ft_printf.h"

int	ft_hexadecimal_pointer(unsigned long long nb)
{
	char			*base;
	char			*buffer;
	int				i;
	unsigned long long	length;

	length = 0;
	base = "0123456789abcdef";
	buffer = (char *)ft_calloc(17, sizeof(char));
	if (!buffer)
		return (-1);
	if (nb == 0)
		return (free(buffer), ft_putchar('0'));
	i = 0;
	while (nb > 0)
	{
		buffer[i++] = base[nb % 16];
		nb /= 16;
	}
	while (--i >= 0)
		length += ft_putchar(buffer[i]);
	return (free(buffer), length);
}