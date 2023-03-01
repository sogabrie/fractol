/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:40:51 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/01 20:44:41 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_strlcpy_new(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	i = 0;
}

int	ft_strncmp(char *s1, char *s2)
{
	size_t	s;

	s = 0;
	while (s1[s] != '\0' || s2[s] != '\0')
	{
		if (s1[s] > s2[s] || s1[s] < s2[s])
			return ((unsigned char)s1[s] - (unsigned char)s2[s]);
		++s;
	}
	return (0);
}

void	str_tolower(char *a)
{
	while (*a)
	{
		if (*a > 64 && *a < 91)
			*a += 32;
		++a;
	}
}

int	chek_args(t_param *ptr, int argc, char **argv)
{
	if (argc < 2 || argc > 4 || argc == 3)
		return (1);
	str_tolower(argv[1]);
	if (ft_strncmp(argv[1], "mandelbrot") || ft_strncmp(argv[1], "julian"))
		ft_strlcpy_new(ptr->name, argv[1]);
	else
		return (1);
	if (argc == 4)
	{
		if (check_arg_julian(&(ptr->julian_x), argv[2]) \
			|| check_arg_julian(&(ptr->julian_y), argv[3]))
			return (1);
	}
	return (0);
}
