
#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "mlx.h"
#include <math.h>

#define	Y_stan 500
#define X_stand 500
#define one_stand 100
#define centerX_stand 2.0
#define centerY_stand 2.0
#define zoom_stand 200
#define	Julian_X_stand -0.37
#define	Julian_y_stand -0.612

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_param
{
	char*	name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	t_color	col;
	double	X;
	double	Y;
	double	centerX;
	double	centerY;
	double	Julian_X;
	double	Julian_y;
	double	one;
	double	zoom;
}			t_param;

void	hooks(t_param *ptr);

void	creat_fract(t_param *ptr);

void	creat_Mandelbrot(t_param *ptr);

void	creat_Julian(t_param *ptr);

int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		deal_mous(int key, int x, int y, t_param *ptr);
int		deal_key(int key, t_param *ptr);

int		ft_close(int key, t_param *ptr);

void	creat_Burning(t_param *ptr);
#endif