/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instru_and_ret.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:43:23 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/01 19:37:01 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_instru_and_ret(void)
{
	write(1, "\nPlease use this commands\n", 26);
	write(1, "--- Mandelbrod ---\n", 20);
	write(1, "---   Julian   ---\n", 20);
	write(1, "For Julian you can add parameters separated by ", 46);
	write(1, "space !ONLY SPACE!\n", 20);
	write(1, "For Example: 0.0 0.0 and -0.36 -0.66\n", 38);
	write(1, "In range of -2.0 to 2.0\n", 24);
	write(1, "Please enter numbers no longer than 18 characters\n", 50);
	write(1, "!Please enter parameters correct in float type!\n", 49);
	write(1, "-> THANK YOU <-\n\n", 18);
	return (0);
}
