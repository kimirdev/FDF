/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:02:04 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/20 17:02:08 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		destroy_win(t_fdf *fdf)
{
	int		i;

	i = 0;
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	while (i < fdf->height)
		free(fdf->mat[i++]);
	free(fdf->mat);
	exit(0);
}

int			deal(int key, t_fdf *fdf)
{
	if (key == 87)
		x_rotate(fdf);
	if (key == 91)
		x_rotate_rev(fdf);
	if (key == 88)
		y_rotate(fdf);
	if (key == 86)
		y_rotate_rev(fdf);
	if (key == 83)
		z_rotate(fdf);
	if (key == 84)
		z_rotate_rev(fdf);
	if (key == 18)
		parallel(fdf);
	if (key == 19)
		isometric(fdf);
	if (key == 20)
		side(fdf);
	if (key == 53)
		destroy_win(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	print_matrix(*fdf);
	return (0);
}

int			deal_key(int key, t_fdf *fdf)
{
	if (key == 69)
		fdf->zoom += 1;
	if (key == 78)
		fdf->zoom -= fdf->zoom - 1 > 0 ? 1 : 0;
	if (key == 126)
		fdf->shift_y -= 50;
	if (key == 125)
		fdf->shift_y += 50;
	if (key == 124)
		fdf->shift_x += 50;
	if (key == 123)
		fdf->shift_x -= 50;
	deal(key, fdf);
	return (0);
}
