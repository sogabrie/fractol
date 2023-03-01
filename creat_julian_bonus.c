/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_julian_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:22:59 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 15:23:03 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	creat_julian_util(t_param *ptr, double i, double j)
{
	double	cr;
	double	ci;
	double	cr2;
	int		m;

	m = 0;
	cr = i;
	ci = j;
	while ((pow(cr, 2.0) + pow(ci, 2.0) <= 4) && m < 250)
	{
		cr2 = cr;
		cr = pow(cr2, 2.0) - pow(ci, 2.0) + ptr->julian_x;
		ci = 2.0 * cr2 * ci + ptr->julian_y;
				m++;
	}
	return (m);
}

void	creat_julian(t_param *ptr, int i, int j)
{
	double long	x;
	double long	y;
	int			col;

	while (i < X_STAND)
	{
		j = 0;
		while (j < Y_STAND)
		{
			x = ptr->start_x + (double)i * (ptr->end_x - ptr->start_x) / X_STAND;
			y = ptr->end_y + (double)j * (ptr->start_y - ptr->end_y) / Y_STAND;
			col = creat_julian_util(ptr, x, y) * 10;
			my_mlx_pixel_put(&(ptr->img), i, j, \
			create_trgb(ptr->col.t, ptr->col.r * (col / 9), ptr->col.g + col, ptr->col.b * (col / 9)));
			++j;
		}
		++i;
	}
}
