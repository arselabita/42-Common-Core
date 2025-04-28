
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	
}

int	main()
{
	char	str[] = "arsela";
	char	*value;
	int	size = 10;

	value = ft_strdup(str);
	printf("the duplicated value is: %s\n", value);
	return (0);
}