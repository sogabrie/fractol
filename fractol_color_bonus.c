/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:50:25 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/01 15:50:27 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	color_do(t_param *par, int key)
{
	if (key == 17)
		par->col.t = (par->col.t + 1) * 5;
	else if (key == 16)
		par->col.t = (par->col.t + 1) / 5;
	else if (key == 15)
		par->col.r = (par->col.r + 1) * 10;
	else if (key == 14)
		par->col.r = (par->col.r + 1) / 10;
	else if (key == 5)
		par->col.g = (par->col.g + 1) * 10;
	else if (key == 3)
		par->col.g = (par->col.g + 1) / 10;
	else if (key == 11)
		par->col.b = (par->col.b + 1) * 10;
	else if (key == 9)
		par->col.b = (par->col.b + 1) / 10;
}
