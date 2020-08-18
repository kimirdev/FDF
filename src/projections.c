/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:59:16 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/20 16:59:17 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		parallel(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->mat[i][j].x = j - fdf->width / 2;
			fdf->mat[i][j].y = i - fdf->height / 2;
			fdf->mat[i][j].z = fdf->mat[i][j].z_stand;
			j++;
		}
		i++;
	}
}

void		isometric(t_fdf *fdf)
{
	int i;

	parallel(fdf);
	i = 0;
	while (i++ < 6)
		x_rotate_rev(fdf);
	while (i++ < 11)
		y_rotate_rev(fdf);
	while (i++ < 18)
		z_rotate(fdf);
}

void		side(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->mat[i][j].x = j - fdf->width / 2.0;
			fdf->mat[i][j].y = ((i - fdf->height / 2.0) * cos(1.57079632679))
					- (fdf->mat[i][j].z_stand * sin(1.57079632679));
			fdf->mat[i][j].z = ((fdf->mat[i][j].z_stand) * cos(1.57079632679))
					+ ((i - fdf->height / 2.0) * sin(1.57079632679));
			j++;
		}
		i++;
	}
}
