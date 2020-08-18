/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:30:25 by bdebbie           #+#    #+#             */
/*   Updated: 2020/02/15 23:30:27 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			print_line(int i, int j, int vec, t_fdf fdf)
{
	int			max;
	float		x_step;
	float		y_step;
	t_matrix	curr;
	t_matrix	next;

	curr = fdf.mat[i][j];
	next = fdf.mat[i + (vec == -1 ? 1 : 0)][j + (vec == -1 ? 0 : 1)];
	fdf.color = choose_color(curr.color, next.color);
	set_params(&curr, &next, fdf);
	x_step = next.x - curr.x;
	y_step = next.y - curr.y;
	max = get_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(curr.x - next.x) || (int)(curr.y - next.y))
	{
		mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, curr.x, curr.y, fdf.color);
		curr.x += x_step;
		curr.y += y_step;
	}
}

void			print_message(t_fdf fdf)
{
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 10, 0xffffff,
		"Arrows - move map");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 30, 0xffffff,
		"(+,-) - zoom");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 60, 0xffffff,
		"Numpad:");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 80, 0xffffff,
		"(4,6) - y axis rotate");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 100, 0xffffff,
		"(5,8) - x axis rotate");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 120, 0xffffff,
		"(1,2) - z axis rotate");
}

void			print_matrix(t_fdf fdf)
{
	int			i;
	int			j;

	i = 0;
	print_message(fdf);
	while (i < fdf.height)
	{
		j = 0;
		while (j < fdf.width)
		{
			if (i + 1 < fdf.height)
				print_line(i, j, -1, fdf);
			if (j + 1 < fdf.width)
				print_line(i, j, 1, fdf);
			j++;
		}
		i++;
	}
}

int				main(int argc, char *argv[])
{
	t_fdf		fdf;
	int			i;

	i = 0;
	fdf = read_map(argv[1]);
	print_matrix(fdf);
	mlx_key_hook(fdf.win_ptr, deal_key, &fdf);
	mlx_loop(fdf.mlx_ptr);
	while (i < fdf.height)
		free(fdf.mat[i++]);
	free(fdf.mat);
	return (0);
}
