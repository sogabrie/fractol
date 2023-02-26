#include "fractol.h"

int	ft_close(int key, t_param *ptr)
{
	(void)key;
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	exit(0);
	return (0);
}