/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_julian_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:37:27 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/04 15:40:45 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (check_sin(b));
}
