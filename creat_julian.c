#include "fractol.h"

int	creat_Julian_util(t_param *ptr, double i, double j)
{
	double	cr;
	double	ci;
	double	cr2;
	int		m;

	m = 0;
	cr = (i / (ptr->zoom));
	ci = (j / (ptr->zoom));
	while ((pow(cr, 2.0) + pow(ci, 2.0) <= 4)&& m  < 100)
	{
		cr2 = cr;
		cr = pow(cr2, 2.0) - pow(ci, 2.0) + ptr->Julian_X;
		ci = 2.0 * cr2 * ci  + ptr->Julian_y;
				m++;
	}
	return (m);
}

void	creat_Julian(t_param *ptr)
{
	double		i;
	double		j;
	int			col;

	i = -(ptr->X / ptr->centerX);
	j = -(ptr->Y / ptr->centerY);
	while (i < ptr->X - fabs((ptr->X / ptr->centerX)))
	{
		j = -(ptr->Y / ptr->centerY);
		while (j < ptr->Y - fabs(ptr->Y / ptr->centerY))
		{
			col = creat_Julian_util(ptr, i, j) * 15;
			my_mlx_pixel_put(&(ptr->img), \
			 (ptr->X / ptr->centerX) + i,(ptr->Y / ptr->centerY) + j, \
			 create_trgb(ptr->col.t,ptr->col.r,ptr->col.g + col,ptr->col.b));
			++j;
		}
		++i;
	}
}