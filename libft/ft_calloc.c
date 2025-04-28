
#include <stdio.h>
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

int main()
{
	int	n;
	int	i;
	int	*ptr;

	n = 5;
	ptr = (int *)ft_calloc(n, sizeof(int));
	printf("%p\n", ptr);

	if (ptr != NULL)
		printf("Memory successfully allocated!!\n");
	i = 0;
	while (i < n)
	{
		printf("%d", ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}