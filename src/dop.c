/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:22:26 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/20 17:22:27 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_max(int a, int b)
{
	return (a > b) ? a : b;
}

int			mod(int a)
{
	return (a < 0) ? -a : a;
}

int			choose_color(int curr, int next)
{
	if (curr || next)
	{
		if (curr > 0 || next > 0)
			return (0x00ced1);
		return (0x7b68ee);
	}
	return (0xff69b4);
}

void		set_params(t_matrix *curr, t_matrix *next, t_fdf fdf)
{
	curr->x *= fdf.zoom;
	curr->y *= fdf.zoom;
	next->x *= fdf.zoom;
	next->y *= fdf.zoom;
	curr->x += fdf.shift_x;
	next->x += fdf.shift_x;
	curr->y += fdf.shift_y;
	next->y += fdf.shift_y;
}
