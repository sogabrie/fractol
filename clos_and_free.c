#include "fractol.h"

int	ft_close(int key, t_param *ptr)
{
	(void)key;
	printf("close\n");
	mlx_destroy_image(ptr->mlx_ptr, &ptr->img);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	exit(0);
	return (0);
}