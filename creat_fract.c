/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:41:22 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 00:41:45 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	creat_fract(t_param *ptr)
{
	if (ft_strcmp_new(ptr->name, "mandelbrod"))
		creat_mandelbrot(ptr);
	else if (ft_strcmp_new(ptr->name, "julian"))
		creat_julian(ptr);
	else
		return (1);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img.img, 0, 0);
	return (0);
}
