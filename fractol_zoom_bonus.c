#include "fractol_bonus.h"

void	zoom_in(t_param *par)
{
	par->zoom *= 2.0;
	printf("zoom in X  = %Lf\n", par->center_x);
	printf("zoom in Y  = %Lf\n", par->center_y);

}

void	zoom_out(t_param *par)
{
	par->zoom /= 1.5;
	printf("zoom out X  = %Lf\n", par->center_x);
	printf("zoom out Y  = %Lf\n", par->center_y);
}

void	do_moov(t_param *par, double long x, double long y)
{
	double long x_2;
	double long y_2;

	x_2 = x / (X_STAND / 2) * 100;
	y_2 = y / (Y_STAND / 2) * 100;
	printf("centor X_2 = %Lf\n", x_2);
	printf("centor Y_2  = %Lf\n", y_2);
	par->center_x = par->center_x / 100 * x_2;
	par->center_y = par->center_y / 100 * y_2;
	// par->center_x = par->center_x - X_STAND / x;
	// par->center_y = par->center_y - Y_STAND / y;
	printf("centor X  = %Lf\n", par->center_x);
	printf("centor Y  = %Lf\n", par->center_y);
}

void	fractol_moov(t_param *par, int key)
{
	int	x = X_STAND / 2;
	int y = Y_STAND / 2;
	if (key == 123)
		x = X_STAND / 2 - X_STAND / 4;
	if (key == 124)
		x = X_STAND / 2 + X_STAND / 4;
	if (key == 126)
		y = Y_STAND / 2 - Y_STAND / 4;
	if (key == 125)
		y = Y_STAND / 2 + Y_STAND / 4;
	do_moov(par, (double)x, (double)y);
}

void	zoom_do(t_param *par, int key, int x, int y)
{
	if (key == 24 || key == 5)
		zoom_in(par);
	if (key == 27 || key == 4)
		zoom_out(par);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		fractol_moov(par, key);
	if (key == 1)
	{
		zoom_in(par);
		do_moov(par, (double long)x, (double long)y);
	}
	if (key == 2)
	{
		zoom_out(par);
		do_moov(par, (double long)x, (double long)y);
	}
}