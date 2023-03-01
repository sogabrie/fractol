/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libs_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:34:55 by sogabrie          #+#    #+#             */
/*   Updated: 2023/02/28 15:34:56 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp_new(const char *s1, const char *s2)
{
	size_t	s;

	s = 0;
	while (s1[s] != '\0' && s2[s] != '\0')
	{
		if (s1[s] > s2[s] || s1[s] < s2[s])
			return (0);
		++s;
	}
	if (s1[s] == '\0' && s2[s] == '\0')
		return (1);
	return (0);
}

void	*ft_memset(void *a, int c, size_t len)
{
	while (0 < len)
	{
		--len;
		((unsigned char *)a)[len] = c;
	}
	return (a);
}

void	ft_bzero(void *a, size_t s)
{
	ft_memset(a, 0, s);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = '\0';
			i = 0;
	}
	while (src[i] != 0)
		++i;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;

	// if (nmemb == SIZE_MAX || size == SIZE_MAX)
	// 	return (0);
	pt = malloc(nmemb * size);
	if (!pt)
		return (0);
	ft_bzero(pt, nmemb * size);
	return (pt);
}
