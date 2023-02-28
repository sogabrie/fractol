#include "fractol_bonus.h"

void	zoom_in(t_param *par)
{
	par->zoom *= 1.5;
}

void	zoom_out(t_param *par)
{
	par->zoom /= 1.5;
}