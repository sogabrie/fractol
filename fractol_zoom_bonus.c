#include "fractol_bonus.h"

void	zoom(t_param *par, double long zoom)
{
	double	long x;
	double	long y;

	x = par->start_x - par->end_x;
	y = par->end_y - par->start_y;
	par->end_x = par->end_x + (x - zoom * x) / 2;
	par->start_x = par->end_x + zoom * x;
	par->start_y = par->start_y + (y - zoom * y) / 2;
	par->end_y = par->start_y + zoom * y;

}

void	do_moov(t_param *par, double long pos, int key)
{
	double long	x;
	double long	y;

	x = par->end_x - par->start_x;
	y = par->end_y - par->start_y;
	if (key == 65363)
	{
		par->start_x += x * pos;
		par->end_x += x * pos;
	}
	else if (key == 65361)
	{
		par->start_x -= x * pos;
		par->end_x -= x * pos;
	}
	else if (key == 65364)
	{
		par->start_y -= y * pos;
		par->end_y -= y * pos;
	}
	else if (key == 65362)
	{
		par->start_y += y * pos;
		par->end_y += y * pos;
	}
}

void	zoom_do(t_param *par, int key, int x, int y)
{
	if (key == 61)
		zoom(par, 0.5);
	else if (key == 45)
		zoom(par, 2);
	else if (key == 65362 || key == 65364 || key == 65363 || key == 65361)
		do_moov(par, 0.1, key);
	else if (key == 4)
	{
		zoom(par, 0.5);
		x -= X_STAND / 2;
		y -= Y_STAND / 2;
		if (x < 0)
			do_moov(par, (double)x * -1 / X_STAND, 65361);
		else if (x > 0)
			do_moov(par, (double)x / X_STAND, 65363);
		if (y < 0)
			do_moov(par, (double)y * -1 / Y_STAND, 65362);
		else if (y > 0)
			do_moov(par, (double)y / Y_STAND, 65364);
	}
	else if (key == 5)
		zoom(par, 2);
	printf("key = %d\n",key);
}