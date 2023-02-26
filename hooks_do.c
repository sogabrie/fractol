#include "fractol.h"

int	deal_mous(int key, int x, int y, t_param *ptr)
{
	(void)x;
	(void)y;
	if (key == 4)
	{
		ptr->zoom *= 1.5;
		creat_fract(ptr);
	}
	if (key == 5)
	{
		ptr->zoom /= 1.5;
		creat_fract(ptr);
	}
	return (0);
}

int	deal_key(int key, t_param *ptr)
{
	if (key == 53)
		mlx_hook(ptr->win_ptr, 2, 1L<<0, ft_close, ptr);
	
	return (0);
}