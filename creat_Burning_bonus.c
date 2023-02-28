/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_Burning_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:41:11 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 00:41:12 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	creat_burning_util(t_param *ptr, double i, double j)
{
	double	cr;
	double	ci;
	double	cr2;
	int		m;

	m = 0;
	cr = 0;
	ci = 0;
	while ((pow(cr, 2.0) + pow(ci, 2.0) < 4) && m < 100)
	{
		cr = fabs(cr);
		ci = fabs(ci);
		cr2 = cr;
		cr = cr * cr - ci * ci + (i / (ptr->zoom));
		ci = 2.0 * cr2 * ci + (j / (ptr->zoom));
		m++;
	}
	return (m);
}

void	creat_burning(t_param *ptr)
{
	double		i;
	double		j;
	int			col;

	i = -(ptr->x / ptr->center_x);
	j = -(ptr->y / ptr->center_y);
	while (i < ptr->x - fabsl((ptr->x / ptr->center_x)))
	{
		j = -(ptr->y / ptr->center_y);
		while (j < ptr->y - fabsl(ptr->y / ptr->center_y))
		{
			col = creat_burning_util(ptr, i, j) * 10;
			my_mlx_pixel_put(&(ptr->img), \
			(ptr->x / ptr->center_x) + i, (ptr->y / ptr->center_y) + j, \
			create_trgb(ptr->col.t, ptr->col.r * (col / 9), ptr->col.g + col, ptr->col.b * (col /9)));
			++j;
		}
		++i;
	}
}
