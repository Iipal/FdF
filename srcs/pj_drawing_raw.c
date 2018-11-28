/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_raw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:18:58 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/27 15:19:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/additional_structs.h"

static void	add_draw_line_x(t_dp delta, t_dp points, t_mlxncolor mnc)
{
	int	x;
	int	y;
	int	dir;
	int	increase;

	dir = ZERO;
	increase = ZERO;
	x = points.p1.x;
	y = points.p1.y;
	if (delta.p1.y)
		dir = delta.p1.y > 0 ? 1 : -1;
	while (((delta.p1.x > 0) ? (x <= points.p2.x) : (x >= points.p2.x)))
	{
		mlx_pixel_put(mnc.mlx->mlx, mnc.mlx->win, x, y, mnc.color);
		increase += delta.p2.y;
		if (increase >= delta.p2.x)
		{
			increase -= delta.p2.x;
			y += dir;
		}
		(delta.p1.x > 0) ? ++x : --x;
	}
}

static void	add_draw_line_y(t_dp delta, t_dp points, t_mlxncolor mnc)
{
	int	x;
	int	y;
	int	dir;
	int	increase;

	dir = ZERO;
	increase = ZERO;
	x = points.p1.x;
	y = points.p1.y;
	if (delta.p1.y)
		dir = (delta.p1.x > 0 ? 1 : -1);
	while (((delta.p1.y > 0) ? (y <= points.p2.y) : (y >= points.p2.y)))
	{
		mlx_pixel_put(mnc.mlx->mlx, mnc.mlx->win, x, y, mnc.color);
		increase += delta.p2.x;
		if (increase >= delta.p2.y)
		{
			increase -= delta.p2.y;
			x += dir;
		}
		(delta.p1.y > 0) ? ++y : --y;
	}
}

static void	add_set_line(t_point point1, t_point point2, t_mlxncolor mnc)
{
	const int	deltax = point2.x - point1.x;
	const int	deltay = point2.y - point1.y;
	const int	absdx = _ABS(deltax);
	const int	absdy = _ABS(deltay);

	if (absdx >= absdy)
		add_draw_line_x((t_dp){.p1.x = deltax,
								.p1.y = deltay,
							.p2.x = absdx,
								.p2.y = absdy},
					(t_dp){.p1 = point1,
							.p2 = point2}, mnc);
	else
		add_draw_line_y((t_dp){.p1.x = deltax,
								.p1.y = deltay,
							.p2.x = absdx,
								.p2.y = absdy},
					(t_dp){.p1 = point1,
							.p2 = point2}, mnc);
}

/*
**	'pj_mlx_draw_matrix' Bresenham algorithm optimization for my code.
*/

void		pj_mlx_draw_matrix(t_mlx *mlx, t_matrix **matrix)
{
	int	y;
	int	x;
	int	dist_x;
	int	dist_y;

	y = NEG;
	dist_y = ZERO;
	while (++y < g_matrix_y)
	{
		x = NEG;
		dist_x = ZERO;
		while (++x < g_matrix_x - 1)
		{
			add_set_line((t_point){.x = matrix[y][x].x * dist_x, .y = matrix[y][x].y * dist_y},
						(t_point){.x = (matrix[y][x].x + 1) * DEC, .y = matrix[y][x].y * dist_y},
						(t_mlxncolor){.mlx = mlx, .color = matrix[y][x].rgb});
			add_set_line((t_point){.x = matrix[y][x].x * dist_x, .y = matrix[y][x].y * dist_y},
						(t_point){.x = matrix[y][x].x * dist_x, .y = (matrix[y][x].y + 1) * DEC},
						(t_mlxncolor){.mlx = mlx, .color = matrix[y][x].rgb});
			dist_x = DEC;
		}
		dist_y = DEC;
	}
}
