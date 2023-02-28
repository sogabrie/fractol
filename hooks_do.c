/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:43:39 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 00:43:41 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_mous(int key, int x, int y, t_param *ptr)
{
	(void)x;
	(void)y;
	printf("mous key = %d\n", key);
	if (key == 4)
	{
		ptr->zoom *= 1.5;
		creat_fract(ptr);
	}
	if (key == 5)
	{
		ptr->zoom /= 1.5;
		creat_fract(ptr);
	}
	return (0);
}

int	deal_key(int key, t_param *ptr)
{
	printf("key key = %d\n", key);
	if (key == 53)
		ft_close(ptr);
	if (key == 24)
	{
		ptr->zoom *= 1.5;
		creat_fract(ptr);
	}
	if (key == 27)
	{
		ptr->zoom /= 1.5;
		creat_fract(ptr);
	}
	return (0);
}
