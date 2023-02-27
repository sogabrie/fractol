#include "fractol.h"

int	ft_isdigit(char a)
{
	if (a > (char)47 && a < (char)58)
		return (1);
	else
		return (0);
}

long long	ft_atoi(char *nptr)
{
	long long	i;
	long long	ptr;

	i = 0;
	ptr = 0;
	if (nptr[i] != 0 && nptr[i] == '+')
		++i;
	while (nptr[i] != 0 && ft_isdigit(nptr[i]))
		ptr = (10 * ptr) + (nptr[i++] - 48);
	return (ptr);
}

double	pars_dobl(char **mas, long long i, long long f)
{
	double long a;
	double long b;
	double long c;

	if (mas[0][0] == '-')
		f = 1;
	//printf("pars_dobl_2 \n");
	i = ft_atoi(mas[1]);
	//printf("pars_dobl_1 i = %lld \n", i);
	c = (double long)i;
	//printf("pars_dobl_1 a_1 = %Lf  len =  %zu\n", c, ft_strlen(mas[1]));
		a = c / pow(10, ft_strlen(mas[1]));
	b = (double long)ft_atoi(mas[0]);
	//printf("doublen_1 = %Lf\n",b);
	if (!b && f)
		b *= -1.0;
	b += a;
	//printf("doublen_2 = %Lf\n",b);
	return (b);
}

int	check_arg_julian(double *jul, char *arg)
{
	char	**a;
	char	**b;

	//printf("check julian_1 arg = %s  \n",arg);
	b = ft_split(arg, ' ');
	if (!b)
		return(1); 
	//printf("check julian_1 b[0] = %s  \n",b[0]);
	a = ft_split((b[0]), '.');
	//printf("check julian_4 a[0] = %s a[1] = %s \n",a[0], a[1]);
	free_mas(&b);
	if (!a)
		return (1);
	//printf("check julian_8 \n");
	*jul = pars_dobl(a, 0, 0);
	//printf("check julian_9 \n");
	free_mas(&a);
	//printf("check julian_10 \n");
	return (0);
}