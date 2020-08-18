/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:27:26 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/20 17:27:27 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				is_ok(t_fdf fdf, t_matrix **mat, char **nums)
{
	int i;
	int j;

	i = 0;
	while (nums[i])
		i++;
	if (fdf.width != i)
		return (0);
	i = 0;
	while (i < fdf.width)
	{
		j = 0;
		while (nums[i][j])
		{
			if ((nums[i][j] == '-' || nums[i][j] == '+') && j != 0)
				return (0);
			if ((nums[i][j] < '0' || nums[i][j] > '9') &&
				nums[i][j] != '-' && nums[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			not_valid_case(t_fdf fdf, t_matrix **mat, int j)
{
	while (--j >= 0)
		free(mat[j]);
	free(mat);
	mlx_destroy_window(fdf.mlx_ptr, fdf.win_ptr);
	write(2, "Not valid map\n", 14);
	exit(0);
}
