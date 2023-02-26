#include "fractol.h"

int	check_name_fractol(t_param *ptr)
{
	(void)ptr;
	return (1);
}

void	creat_fract(t_param *ptr)
{
	// if (check_name_fractol(ptr))
	// 	creat_Mandelbrot(ptr);
	if (check_name_fractol(ptr))
		creat_Julian(ptr);
	// else if (check_name_fractol(ptr->name))
	// 	creat_hl_chgitem?
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img.img, 0, 0);
}