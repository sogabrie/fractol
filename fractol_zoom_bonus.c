/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_zoom_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:51:42 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/01 17:04:55 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	zoom(t_param *par, double long zoom)
{
	double long	x;
	double long	y;

	x = par->start_x - par->end_x;
	y = par->end_y - par->start_y;
	par->end_x = par->end_x + (x - zoom * x) / 2.0;
	par->start_x = par->end_x + zoom * x;
	par->start_y = par->start_y + (y - zoom * y) / 2.0;
	par->end_y = par->start_y + zoom * y;
}

void	do_moov(t_param *par, double long pos, int key)
{
	double long	x;
	double long	y;

	x = par->end_x - par->start_x;
	y = par->end_y - par->start_y;
	if (key == 124)
	{
		par->start_x += x * pos;
		par->end_x += x * pos;
	}
	else if (key == 123)
	{
		par->start_x -= x * pos;
		par->end_x -= x * pos;
	}
	else if (key == 125)
	{
		par->start_y -= y * pos;
		par->end_y -= y * pos;
	}
	else if (key == 126)
	{
		par->start_y += y * pos;
		par->end_y += y * pos;
	}
}

void	zoom_do(t_param *par, int key, double long x, double long y)
{
	if (key == 24)
		zoom(par, 0.5);
	else if (key == 27)
		zoom(par, 2.0);
	else if (key == 125 || key == 126 || key == 123 || key == 124)
		do_moov(par, 0.1, key);
	else if (key == 4)
	{
		zoom(par, 0.5);
		x -= X_STAND / 2;
		y -= Y_STAND / 2;
		if (x < 0)
			do_moov(par, x * -1.0 / X_STAND, 123);
		else if (x > 0)
			do_moov(par, x / X_STAND, 124);
		if (y < 0)
			do_moov(par, y * -1.0 / Y_STAND, 125);
		else if (y > 0)
			do_moov(par, y / Y_STAND, 126);
	}
	else if (key == 5)
		zoom(par, 2.0);
}
