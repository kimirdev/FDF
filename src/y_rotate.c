/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:54:05 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/20 16:54:07 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		y_rotate(t_fdf *fdf)
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
			fdf->mat[i][j].x = x1 * cos(fdf->angle) + z1 * sin(fdf->angle);
			fdf->mat[i][j].z = z1 * cos(fdf->angle) - x1 * sin(fdf->angle);
			j++;
		}
		i++;
	}
}

void		y_rotate_rev(t_fdf *fdf)
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
			fdf->mat[i][j].x = x1 * cos(fdf->angle) - z1 * sin(fdf->angle);
			fdf->mat[i][j].z = z1 * cos(fdf->angle) + x1 * sin(fdf->angle);
			j++;
		}
		i++;
	}
}
