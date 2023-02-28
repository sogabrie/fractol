/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_do_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:35:51 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 15:35:53 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	deal_mous(int key, int x, int y, t_param *ptr)
{
	(void)x;
	(void)y;
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
	if (key == 53)
		ft_close(ptr);
	if (key == 0)
		ptr->zoom *= 1.5;
	if (key == 1)
		ptr->zoom /= 1.5;
	creat_fract(ptr);
	return (0);
}
