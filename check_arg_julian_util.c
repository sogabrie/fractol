#include "fractol.h"

int	check_sin(char *b)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (b[i])
	{
		if (b[i] == '.')
			++f;
		if (f > 1)
			return (1);
		++i;
	}
	return (0);
}

int	check_b(char *b)
{
	int	i;

	i = 0;
	printf("check_b_1\n");
	while (b[i])
	{
		if (i == 0)
		{
			if (!ft_isdigit(b[i]) && b[i] != '+' && b[i] != '-')
				return (1);
		}
		else if (b[i + 1] == 0)
		{
			if (!ft_isdigit(b[i]))
				return (1);
		}
		else
			if (!ft_isdigit(b[i]) && b[i] != '.')
				return (1);
		++i;
	}
	printf("check_b_10\n");
	return (check_sin(b));
}