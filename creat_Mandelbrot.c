/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_Mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:42:10 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/01 17:11:28 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	creat_mandelbrot_util(t_param *ptr, double i, double j)
{
	double	cr;
	double	ci;
	double	cr2;
	int		m;

	m = 0;
	cr = (i / (ptr->zoom));
	ci = (j / (ptr->zoom));
	while ((pow(cr, 2.0) + pow(ci, 2.0) <= 4) && m < 100)
	{
		cr2 = cr;
		cr = pow(cr2, 2.0) - pow(ci, 2.0) + (i / (ptr->zoom));
		ci = 2.0 * cr2 * ci + (j / (ptr->zoom));
		m++;
	}
	return (m);
}

void	creat_mandelbrot(t_param *ptr)
{
	double		i;
	double		j;
	int			col;

	i = -(ptr->x / ptr->center_x);
	j = -(ptr->y / ptr->center_y);
	while (i < ptr->x - fabs((ptr->x / ptr->center_x)))
	{
		j = -(ptr->y / ptr->center_y);
		while (j < ptr->y - fabs(ptr->y / ptr->center_y))
		{
			col = creat_mandelbrot_util(ptr, i, j) * 15;
			my_mlx_pixel_put(&(ptr->img), \
			(ptr->x / ptr->center_x) + i, (ptr->y / ptr->center_y) + j, \
			create_trgb(ptr->col.t, ptr->col.r, \
			ptr->col.g + col, ptr->col.b));
			++j;
		}
		++i;
	}
}
