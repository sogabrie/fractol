/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fract_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:22:41 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 15:23:16 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	creat_fract(t_param *ptr)
{
	if (ft_strcmp_new(ptr->name, "mandelbrod"))
		creat_mandelbrot(ptr);
	else if (ft_strcmp_new(ptr->name, "julian"))
		creat_julian(ptr);
	else if (ft_strcmp_new(ptr->name, "burning"))
		creat_burning(ptr);
	else
		return (1);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img.img, 0, 0);
	return (0);
}
