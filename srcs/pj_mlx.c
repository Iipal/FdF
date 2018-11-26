/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:45:51 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/23 13:45:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	*pj_mlx_init(cstring tittle)
{
	t_mlx	*out;

	_NOTIS_N(out = (t_mlx*)malloc(sizeof(t_mlx)));
	_NOTIS_N(out->mlx = mlx_init());
	_NOTIS_N(out->win = mlx_new_window(out->mlx,
					WIN_X, WIN_Y, (string)tittle));
	mlx_loop(out->mlx);
	return (out);
}
/*
static void	add_draw_line(t_point delta, size_t *increase,
							t_mlx *mlx, t_matrix *matrix)
{
}

static void add_set_line(t_point p1, t_point p2, t_mlx *mlx, t_matrix *matrix)
{
	const size_t	deltax = x1 - x2;
	const size_t	deltay = y1 - y0;
	const size_t	absdx = _ABS(deltax);
	const size_t	absdy = _ABS(deltay);
	size_t			increase;

	increase = ZERO;
	if (absdx >= absdy)
	{
		add_draw_line((t_point){.x = (size_t)deltax, .y (size_t)deltay},
						&increase, mlx, matrix);
	}
}

void	pj_mlx_draw_raw_matrix(t_mlx *mlx, t_matrix **matrix)
{
	size_t	y;
	size_t	x;
	size_t	dist_x;
	size_t	dist_y;

	y = ZERO;
	dist_y = ZERO;
	while (y < g_matrix_y)
	{
		x = ZERO;
		dist_x = ZERO;
		while (x < g_matrix_x)
		{
			++x;
		}
		++y;
	}
}
*/