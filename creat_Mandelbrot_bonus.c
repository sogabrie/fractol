/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_Mandelbrot_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:23:25 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/01 17:13:05 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	creat_mandelbrot_util(double long i, double long j)
{
	double	cr;
	double	ci;
	double	cr2;
	int		m;

	m = 0;
	cr = 0;
	ci = 0;
	while ((pow(cr, 2.0) + pow(ci, 2.0) <= 4) && m < 250)
	{
		cr2 = cr;
		cr = pow(cr2, 2.0) - pow(ci, 2.0) + i;
		ci = 2.0 * cr2 * ci + j;
		m++;
	}
	return (m);
}

void	creat_mandelbrot(t_param *ptr, double long i, double long j)
{
	double long	x;
	double long	y;
	int			col;

	while (i < X_STAND)
	{
		j = 0;
		while (j < Y_STAND)
		{
			x = ptr->start_x + i * (ptr->end_x - ptr->start_x) / X_STAND;
			y = ptr->end_y + j * (ptr->start_y - ptr->end_y) / Y_STAND;
			col = creat_mandelbrot_util(x, y) * 10;
			my_mlx_pixel_put(&(ptr->img), i, j, \
			create_trgb(ptr->col.t, ptr->col.r * (col / 10), \
			ptr->col.g + col, ptr->col.b * (col / 10)));
			++j;
		}
		++i;
	}
}
