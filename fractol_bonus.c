/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:26:34 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/01 17:07:02 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	initalizatia_args(t_param *ptr)
{
	ptr->col.t = 1;
	ptr->col.r = 24;
	ptr->col.g = 2;
	ptr->col.b = 16;
	ptr->julian_x = JULIAN_X_STAND;
	ptr->julian_y = JULIAN_Y_STAND;
}

void	get_reng_fractol(t_param *para)
{
	if (ft_strcmp_new(para->name, "julian"))
	{
		para->start_x = -2.0;
		para->end_x = 2.0;
		para->start_y = -2.0;
		para->end_y = para->start_y + (para->end_x - para->start_x) \
		* Y_STAND / X_STAND;
	}
	else
	{
		para->start_x = -2.0;
		para->end_x = 1.0;
		para->end_y = -1.5;
		para->start_y = para->end_y + (para->end_x - para->start_x) \
		* Y_STAND / X_STAND;
	}
}

int	inicalizacia_and_check(t_param *ptr, int argc, char **argv)
{
	initalizatia_args(ptr);
	if (chek_args(ptr, argc, argv))
		return (1);
	get_reng_fractol(ptr);
	return (0);
}

int	hooks(t_param *ptr)
{
	if (creat_fract(ptr))
		return (1);
	mlx_mouse_hook(ptr->win_ptr, deal_mous, ptr);
	mlx_key_hook(ptr->win_ptr, deal_key, ptr);
	mlx_hook(ptr->win_ptr, 17, 1L << 17, ft_close, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	ptr;

	if (inicalizacia_and_check(&ptr, argc, argv))
		return (get_instru_and_ret());
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, X_STAND, Y_STAND, "Fractol");
	ptr.img.img = mlx_new_image(ptr.mlx_ptr, X_STAND, Y_STAND);
	ptr.img.addr = mlx_get_data_addr(ptr.img.img, &(ptr.img.bits_per_pixel), \
					&(ptr.img.line_length), &(ptr.img.endian));
	if (hooks(&ptr))
		get_instru_and_ret();
	ft_close(&ptr);
	return (0);
}
