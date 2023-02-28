/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_julian_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:43:55 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 15:43:57 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	double long	a;
	double long	b;
	double long	c;

	if (mas[0][0] == '-')
		f = 1;
	i = ft_atoi(mas[1]);
	c = (double long)i;
		a = c / pow(10, ft_strlen(mas[1]));
	b = (double long)ft_atoi(mas[0]);
	if (!b && f)
		b *= -1.0;
	b += a;
	return (b);
}

int	check_arg_julian(double *jul, char *arg)
{
	char	**a;
	char	**b;

	b = ft_split(arg, ' ');
	if (!b)
		return (1);
	a = ft_split((b[0]), '.');
	free_mas(&b);
	if (!a)
		return (1);
	if (ft_strlen(a[1]) > 19)
		return (free_mas(&b) || 1);
	*jul = pars_dobl(a, 0, 0);
	free_mas(&a);
	return (0);
}
