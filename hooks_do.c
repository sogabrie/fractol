#include "fractol.h"

int	deal_mous(int key, int x, int y, t_param *ptr)
{
	printf("key = %d x = %d y = %d\n",key, x, y);
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
	printf("key key == %d", key);
	if (key == 53)
		ft_close(ptr);
	if (key == 0)
		printf("key key == %d", key);
	if (key == 0)
	{
		ptr->zoom *= 1.5;
		creat_fract(ptr);
	}
	if (key == 1)
	{
		ptr->zoom /= 1.5;
		creat_fract(ptr);
	}
	return (0);
}