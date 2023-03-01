/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_do_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:35:51 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 15:35:53 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	deal_mous(int key, int x, int y, t_param *ptr)
{
	// printf("mous key = %d\n", key);
	// if (key == 4 || key == 5 || key == 1 || key == 2)
	// 	zoom_do(ptr, key, x, y);
	// else
	// 	return (0);
	// creat_fract(ptr);
	// return (0);
	printf("mous key = %d\n", key);
	if (key == 4 || key == 5 || key == 1 || key == 3)
		zoom_do(ptr, key, x, y);
	else
		return (0);
	creat_fract(ptr);
	return (0);
}

int	deal_key(int key, t_param *ptr)
{
	// printf("key key = %d\n", key);
	// if (key == 53)
	// 	ft_close(ptr);
	// else if (key == 24 || key == 27 || key == 123 \
	// 	|| key == 124 || key == 125 || key == 126)
	// 	zoom_do(ptr, key, 0, 0);
	// else if (key == 17 || key == 16 || key == 15 \
	// 	|| key == 14 || key == 5 || key == 3 || key == 11 || key == 9)
	// 	color_do(ptr, key);
	// else
	// 	return (0);
	// creat_fract(ptr);
	// return (0);
		printf("key key = %d\n", key);
	if (key == 53)
		ft_close(ptr);
	else if (key == 61 || key == 45 || key == 65364 \
		|| key == 65362 || key == 65361 || key == 65363)
		zoom_do(ptr, key, 0, 0);
	else if (key == 17 || key == 16 || key == 15 \
		|| key == 14 || key == 5 || key == 3 || key == 11 || key == 9)
		color_do(ptr, key);
	else
		return (0);
	creat_fract(ptr);
	return (0);
}
