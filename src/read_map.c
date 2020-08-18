/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:54:22 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/14 14:54:24 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_height(char *file_name)
{
	char		*line;
	int			fd;
	int			height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int				get_width(char *file_name)
{
	int			width;
	int			fd;
	char		*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_cw(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int				set_color(float z)
{
	if (z == 0.0)
		return (0);
	if (z > 0.0)
		return (1);
	if (z < 0.0)
		return (-1);
	return (0);
}

void			fill_matrix(t_matrix **mat, char *line, int j, t_fdf fdf)
{
	char		**nums;
	int			i;

	nums = ft_strsplit(line, ' ');
	if (!is_ok(fdf, mat, nums))
		not_valid_case(fdf, mat, j);
	mat[j] = (t_matrix*)malloc(sizeof(t_matrix) * fdf.width + 1);
	i = 0;
	while (nums[i])
	{
		mat[j][i].z = ft_atoi(nums[i]) / 5.0;
		mat[j][i].z_stand = mat[j][i].z;
		mat[j][i].y = j - (fdf.height / 2.0);
		mat[j][i].x = i - (fdf.width / 2.0);
		mat[j][i].color = set_color(mat[j][i].z);
		free(nums[i]);
		i++;
	}
	free(nums);
}

t_fdf			read_map(char *file_name)
{
	int			j;
	int			fd;
	char		*line;
	t_fdf		fdf;
	t_matrix	**mat;

	j = 0;
	fdf.height = get_height(file_name);
	fdf.width = get_width(file_name);
	fdf.zoom = 30;
	fdf.shift_x = 500;
	fdf.shift_y = 500;
	fdf.angle = 0.1;
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1000, 1000, "FDF");
	fd = open(file_name, O_RDONLY, 0);
	mat = (t_matrix **)malloc(sizeof(t_matrix *) * (fdf.height));
	while (get_next_line(fd, &line))
	{
		fill_matrix(mat, line, j, fdf);
		free(line);
		j++;
	}
	fdf.mat = mat;
	return (fdf);
}
