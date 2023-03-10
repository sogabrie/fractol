/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:26:44 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/01 20:45:41 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define X_STAND		500.0
# define Y_STAND		500.0
# define JULIAN_X_STAND	-0.37
# define JULIAN_Y_STAND	-0.612

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_param
{
	char		name[20];
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;
	t_color		col;
	double long	start_x;
	double long	start_y;
	double long	end_x;
	double long	end_y;
	double long	julian_x;
	double long	julian_y;
}			t_param;

int		hooks(t_param *ptr);
int		get_instru_and_ret(void);

int		creat_fract(t_param *ptr);

void	creat_mandelbrot(t_param *ptr, double long i, double long j);

void	creat_julian(t_param *ptr, double long i, double long j);

void	creat_burning(t_param *ptr, double long i, double long j);

size_t	ft_strlen(const char *a );
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		deal_mous(int key, int x, int y, t_param *ptr);
int		deal_key(int key, t_param *ptr);

int		ft_close(t_param *ptr);
int		free_mas(char ***mas);

char	**ft_split(char const *s, char c);

int		chek_args(t_param *ptr, int argc, char **argv);

int		check_arg_julian(double long *jul, char *arg);
int		check_b(char *b);
int		ft_isdigit(char a);

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strcmp_new(const char *s1, const char *s2);

void	color_do(t_param *par, int key);
void	zoom_do(t_param *par, int key, double long x, double long y);

#endif
