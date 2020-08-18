/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:50:07 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/20 16:50:10 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		x_rotate(t_fdf *fdf)
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
			fdf->mat[i][j].y = y1 * cos(fdf->angle) + z1 * sin(fdf->angle);
			fdf->mat[i][j].z = z1 * cos(fdf->angle) - y1 * sin(fdf->angle);
			j++;
		}
		i++;
	}
}

void		x_rotate_rev(t_fdf *fdf)
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
			fdf->mat[i][j].y = y1 * cos(fdf->angle) - z1 * sin(fdf->angle);
			fdf->mat[i][j].z = z1 * cos(fdf->angle) + y1 * sin(fdf->angle);
			j++;
		}
		i++;
	}
}
