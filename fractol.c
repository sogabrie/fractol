/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:42:44 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 00:42:45 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initalizatia_args(t_param *ptr)
{
	ptr->col.t = 1;
	ptr->col.r = 24;
	ptr->col.g = 2;
	ptr->col.b = 16;
	ptr->x = X_STAND;
	ptr->y = Y_STAND;
	ptr->center_x = CENTERX_STAND;
	ptr->center_y = CENTERY_STAND;
	ptr->julian_x = JULIAN_X_STAND;
	ptr->julian_y = JULIAN_Y_STAND;
	ptr->one = ONE_STAND;
	ptr->zoom = ZOOM_STAND;
}

int	inicalizacia_and_check(t_param *ptr, int argc, char **argv)
{
	initalizatia_args(ptr);
	if (chek_args(ptr, argc, argv))
		return (1);
	return (0);
}

void	hooks(t_param *ptr)
{
	creat_fract(ptr);
	printf("hookc_2\n");
	mlx_mouse_hook(ptr->win_ptr, deal_mous, ptr);
	mlx_key_hook(ptr->win_ptr, deal_key, ptr);
	mlx_hook(ptr->win_ptr, 17, 1L << 17, ft_close, ptr);
	mlx_loop(ptr->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_param	ptr;

	if (inicalizacia_and_check(&ptr, argc, argv))
		return (get_instru_and_ret());
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, ptr.x, ptr.y, "Window");
	printf("main_2\n");
	ptr.img.img = mlx_new_image(ptr.mlx_ptr, ptr.x, ptr.y);
	printf("main_3\n");
	ptr.img.addr = mlx_get_data_addr(ptr.img.img, &(ptr.img.bits_per_pixel), \
					&(ptr.img.line_length), &(ptr.img.endian));
	hooks(&ptr);
	printf("main_4\n");
	return (0);
}
