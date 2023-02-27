/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clos_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:40:58 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 00:41:00 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	free_mas(char ***mas)
{
	int	i;

	i = 0;
	if (*mas)
		return (0);
	while ((*mas)[i])
	{
		free((*mas)[i]);
		(*mas)[i] = 0;
		++i;
	}
	(*mas) = 0;
	return (0);
}

int	ft_close(t_param *ptr)
{
	printf("close\n");
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img.img);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	exit(0);
	return (0);
}
