#include "fractol.h"

int	deal_mous(int key, int x, int y, t_param *ptr)
{
	printf("key = %d\n",key);
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
	if (key == 3)
	{	
		printf("HOOOOOOK\n");
		mlx_destroy_image(ptr->mlx_ptr, &ptr->img);
		free(ptr->img.addr);
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
		exit(0);
		mlx_hook(ptr->win_ptr, 2, 1L<<0, ft_close, ptr);
	}
	return (0);
}

int	deal_key(int key, t_param *ptr)
{
	if (key == 53)
		mlx_hook(ptr->win_ptr, 2, 1L<<0, ft_close, ptr);
	
	return (0);
}