#include "fractol_bonus.h"

void	

void	zoom_do(t_param *par, int key, int x, int y)
{
	if (key == 24 || key == 5)
		zoom_in(par);
	if (key = 27 || key == 4)
		zoom_out(par);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		fraktol_moov(par, key);
	if (key == 1 || key == 2)
		moov_zoom(par, key, x, y);

}