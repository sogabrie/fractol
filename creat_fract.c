#include "fractol.h"

void	creat_fract(t_param *ptr)
{
	printf("name = %s\n", ptr->name);
	if (ft_strcmp_new(ptr->name, "mandelbrod"))
		creat_Mandelbrot(ptr);
	else if (ft_strcmp_new(ptr->name, "julian"))
	{
		printf("creat julian \n");
		creat_Julian(ptr);
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img.img, 0, 0);
}