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

void	creat_fract(t_param *ptr)
{
	printf("name = %s\n", ptr->name);
	if (ft_strcmp_new(ptr->name, "mandelbrod"))
		creat_mandelbrot(ptr);
	else if (ft_strcmp_new(ptr->name, "julian"))
		creat_julian(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img.img, 0, 0);
}
