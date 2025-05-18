#include "ft_printf.h"
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	int a;

	a = 0;

	a = ft_printf("invalid: %");
	printf("%d", a);
	// h = printf("invalid: %");
	// printf("%d", h);

	// tests for strings
	printf("\n string tests:\n");
	//
	printf("\nlength is: %d\n", ft_printf("test %s, %s, another test %s, after", "string here", "str\0teere", NULL));
	printf("\nlength is: %d\n", printf("test %s, %s, another test %s, after", "string here", "str\0teere", (char *) NULL));
	
	// int tests
	printf("\n int tests:\n");
	//
	printf("\nlength is: %d\n", ft_printf("test %d, Max %d, Min %d, after", 123, 2147483647, -2147483648));
	printf("\nlength is: %d\n", printf("test %d, Max %d, Min %d, after", 123, (int) 2147483647, (int) -2147483648));
	printf("\nlength is: %d\n", ft_printf("test %d, Max %d, Min %d, after", 123, 2147483648, -2147483649));
	printf("\nlength is: %d\n", printf("test %d, Max %d, Min %d, after", 123, (int) 2147483648, (int) -2147483649));
	printf("\nlength is: %d\n", ft_printf("test %i, Max %i, Min %i, after", 123, 2147483647, -2147483648));
	printf("\nlength is: %d\n", printf("test %i, Max %i, Min %i, after", 123, (int) 2147483647, (int) -2147483648));
	printf("\nlength is: %d\n", ft_printf("test %i, Max %i, Min %i, after", 123, 2147483648, -2147483649));
	printf("\nlength is: %d\n", printf("test %i, Max %i, Min %i, after", 123, (int) 2147483648, (int) -2147483649));

	// unsigned int tests
	printf("\n unsigned int tests:\n");
	//
	printf("\nlength is: %d\n", ft_printf("test %u, Max %u, Min %u, after", 123, (unsigned int) 4294967295, 0 ));
	printf("\nlength is: %d\n", printf("test %u, Max %u, Min %u, after", 123, (unsigned int) 4294967295, 0));
	printf("\nlength is: %d\n", ft_printf("test %u, Max %u, Min %u, after", 123, (unsigned int) 4294967296, (unsigned int) -1 ));
	printf("\nlength is: %d\n", printf("test %u, Max %u, Min %u, after", 123, (unsigned int) 4294967296, (unsigned int) -1));

	// char tests
	printf("\n pointer tests:\n");
	//
	char	*test = "blabla";
	int		i = 0;
	printf("\nlength is: %d\n", ft_printf("test %p, str %p, str %p, after int", test, &test[2], &test[4]));
	printf("\nlength is: %d\n", printf("test %p, str %p, str %p, after int", test, &test[2], &test[4]));
	printf("\nlength is: %d\n", ft_printf("test %p, null %p, after int", NULL, &i));
	printf("\nlength is: %d\n", printf("test %p, null %p, after int", NULL, &i));

	// hex tests
	printf("\n hex tests:\n");
	//
	printf("\nlength is: %d\n", ft_printf("test %x, Max %x, Min %x, after", 123, (unsigned int) 4294967295, 0 ));
	printf("\nlength is: %d\n", printf("test %x, Max %x, Min %x, after", 123, (unsigned int) 4294967295, 0));
	printf("\nlength is: %d\n", ft_printf("test %x, Max %x, Min %x, after", 123, (unsigned int) 4294967296, (unsigned int) -1 ));
	printf("\nlength is: %d\n", printf("test %x, Max %x, Min %x, after", 123, (unsigned int) 4294967296, (unsigned int) -1));
	printf("\nlength is: %d\n", ft_printf("test %x, Max %x, Min %x, after", 873, (unsigned int) 42949, (unsigned int) 9999 ));
	printf("\nlength is: %d\n", printf("test %x, Max %x, Min %x, after", 873, (unsigned int) 42949, (unsigned int) 9999));
	ft_printf("\n");
	printf("\nlength is: %d\n", ft_printf("test %X, Max %X, Min %X, after", 123, (unsigned int) 4294967295, 0 ));
	printf("\nlength is: %d\n", printf("test %X, Max %X, Min %X, after", 123, (unsigned int) 4294967295, 0));
	printf("\nlength is: %d\n", ft_printf("test %X, Max %X, Min %X, after", 123, (unsigned int) 4294967296, (unsigned int) -1 ));
	printf("\nlength is: %d\n", printf("test %X, Max %X, Min %X, after", 123, (unsigned int) 4294967296, (unsigned int) -1));
	printf("\nlength is: %d\n", ft_printf("test %X, Max %X, Min %X, after", 873, (unsigned int) 42949, (unsigned int) 9999 ));
	printf("\nlength is: %d\n", printf("test %X, Max %X, Min %X, after", 873, (unsigned int) 42949, (unsigned int) 9999));

	// null check
	printf("\n NULL tests:\n");
	//
	printf("\nlength is: %d\n", ft_printf(NULL));
	printf("\nlength is: %d\n", printf(NULL));
	
	// character checks
	printf("\n character tests:\n");
	//
	printf("\nlength is: %d\n", ft_printf("test %c, %c, another test %c, after", '?', 2, 200));
	printf("\nlength is: %d\n", printf("test %c, %c, another test %c, after", '?', 2, 200));
	printf("\nlength is: %d\n", ft_printf("test %c, %c, another test %c, after", 'a', 'b', '1'));
	printf("\nlength is: %d\n", printf("test %c, %c, another test %c, after", 'a', 'b', '1'));

	// percentage checks
	printf("\n percentage%% tests:\n");
	//
	printf("\nlength is: %d\n", ft_printf("test %%, %%, another test %%, after"));
	printf("\nlength is: %d\n", printf("test %%, %%, another test %%, after"));

	// invalid format specifiers
	printf("\n invalid format specifiers\n");
	//
	printf("\nlength is: %d\n", ft_printf("test %, %%, another test %%, after", 12));
	printf("\nlength is: %d\n", printf("test %c, %%, another test %%, after", 'A'));
	printf("\nlength is: %d\n", ft_printf("%%%%%%%%%% "));
	printf("\nlength is: %d\n", printf("%%%%%%%%%% "));
}