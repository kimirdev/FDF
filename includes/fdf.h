/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:37:02 by gyellowj          #+#    #+#             */
/*   Updated: 2020/02/15 19:37:03 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 4

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libft.h>
# include <mlx.h>

typedef struct	s_matrix
{
	float		x;
	float		y;
	float		z;
	float		z_stand;
	int			color;
}				t_matrix;

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	float		angle;

	t_matrix	**mat;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

t_fdf			read_map(char *file_name);
int				get_next_line(const int fd, char **line);
void			x_rotate(t_fdf *fdf);
void			x_rotate_rev(t_fdf *fdf);
void			y_rotate(t_fdf *fdf);
void			y_rotate_rev(t_fdf *fdf);
void			z_rotate(t_fdf *fdf);
void			z_rotate_rev(t_fdf *fdf);
void			parallel(t_fdf *fdf);
void			isometric(t_fdf *fdf);
void			side(t_fdf *fdf);
int				deal_key(int key, t_fdf *fdf);
void			print_matrix(t_fdf fdf);
void			set_params(t_matrix *curr, t_matrix *next, t_fdf fdf);
int				choose_color(int curr, int next);
int				mod(int a);
int				get_max(int a, int b);
void			not_valid_case(t_fdf fdf, t_matrix **mat, int j);
int				is_ok(t_fdf fdf, t_matrix **mat, char **nums);

#endif
