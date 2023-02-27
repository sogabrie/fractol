#include "fractol.h"

void	initalizatia_args(t_param *ptr)
{
	ptr->col.t = 1;
	ptr->col.r = 24;
	ptr->col.g = 2;
	ptr->col.b = 16;
	ptr->X = X_stand;
	ptr->Y = Y_stan;
	ptr->centerX = centerX_stand;
	ptr->centerY = centerY_stand;
	ptr->Julian_X = Julian_X_stand;
	ptr->Julian_Y = Julian_y_stand;
	ptr->one = one_stand;
	ptr->zoom = zoom_stand;
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
	mlx_hook(ptr->win_ptr, 17, 1L<<17, ft_close, ptr);
	mlx_loop(ptr->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_param	ptr;
	if (inicalizacia_and_check(&ptr, argc, argv))
		return (get_instru_and_ret());
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, ptr.X, ptr.Y, "Window");
	printf("main_2\n");
	ptr.img.img = mlx_new_image(ptr.mlx_ptr, ptr.X, ptr.Y);
	printf("main_3\n");
	ptr.img.addr = mlx_get_data_addr(ptr.img.img, &(ptr.img.bits_per_pixel),&(ptr.img.line_length),&(ptr.img.endian));
	hooks(&ptr);
	printf("main_4\n");
	//return (free_and_closet(&ptr));
	return (0);
}