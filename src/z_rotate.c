/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:55:39 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/20 16:55:40 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		z_rotate(t_fdf *fdf)
{
	float	x1;
	float	y1;
	float	z1;
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			x1 = fdf->mat[i][j].x;
			y1 = fdf->mat[i][j].y;
			z1 = fdf->mat[i][j].z;
			fdf->mat[i][j].x = x1 * cos(fdf->angle) - y1 * sin(fdf->angle);
			fdf->mat[i][j].y = x1 * sin(fdf->angle) + y1 * cos(fdf->angle);
			j++;
		}
		i++;
	}
}

void		z_rotate_rev(t_fdf *fdf)
{
	float	x1;
	float	y1;
	float	z1;
	int		i;
	int		j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			x1 = fdf->mat[i][j].x;
			y1 = fdf->mat[i][j].y;
			z1 = fdf->mat[i][j].z;
			fdf->mat[i][j].x = x1 * cos(fdf->angle) + y1 * sin(fdf->angle);
			fdf->mat[i][j].y = -x1 * sin(fdf->angle) + y1 * cos(fdf->angle);
			j++;
		}
		i++;
	}
}
