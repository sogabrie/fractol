#include "fractol_bonus.h"

void	color_do(t_param *par, int key)
{
	if (key == 17)
		par->col.t = (par->col.t + 1) * 5;
	if (key == 16)
		par->col.t = (par->col.t + 1) / 5;
	if (key == 15)
		par->col.r = (par->col.r + 1) * 10;
	if (key == 14)
		par->col.r = (par->col.r + 1) / 10;
	if (key == 5)
		par->col.g = (par->col.g + 1) * 10;
	if (key == 3)
		par->col.g = (par->col.g + 1) / 10;
	if (key == 11)
		par->col.b = (par->col.b + 1) * 10;
	if (key == 9)
		par->col.b = (par->col.b + 1) / 10;
}