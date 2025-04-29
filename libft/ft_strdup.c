
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int	i;
	char	*s2;

	s2 = (char *)malloc(sizeof(s1) + 1);
	if  (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

int	main()
{
	const char	*str = "hellowww";
	char	*duplicate;

	duplicate = ft_strdup(str);
	if (duplicate != NULL)
	{
		printf("the original string: %s\n", str);
		printf("the duplicated string: %s\n", duplicate);
		free(duplicate);
	}
	else
		printf("Memoryy allocation failed.\n");
	return (0);
}
