/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_drawing_raw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:18:58 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/27 15:19:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/additional_structs.h"

/*
**	'pj_mlx_draw_matrix' Bresenham algorithm optimization for my code.
*/

static void	add_draw_line_x(t_dp delta, t_dp points, t_mlxncolor mnc)
{
	int	y;
	int	x;
	int	dir;
	int	increase;

	dir = ZERO;
	increase = ZERO;
	y = points.p1.y;
	x = points.p1.x;
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
	y = points.p1.y;
	x = points.p1.x;
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

void		pj_drawing_raw(t_mlx *mlx, t_matrix **m)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			if ((x + 1 < g_matrix_x) && (y + 1 < g_matrix_y))
			{
				add_set_line((t_p){.y = m[y][x].y, .x = m[y][x].x},
					(t_p){.y = m[y][x + 1].y, .x = m[y][x + 1].x},
					(t_mlxncolor){.mlx = mlx, .color = m[y][x].rgb});
				add_set_line((t_p){.y = m[y][x].y, .x = m[y][x].x},
					(t_p){.y = m[y + 1][x].y, .x = m[y + 1][x].x},
					(t_mlxncolor){.mlx = mlx, .color = m[y][x].rgb});
			}
			else if (x == g_matrix_x - 1 && y + 1 < g_matrix_y)
				add_set_line((t_p){.y = m[y][x].y, .x = m[y][x].x},
					(t_p){.y = m[y + 1][x].y, .x = m[y + 1][x].x},
					(t_mlxncolor){.mlx = mlx, .color = m[y][x].rgb});
			else if (y == g_matrix_y - 1 && x + 1 < g_matrix_x)
				add_set_line((t_p){.y = m[y][x].y, .x = m[y][x].x},
					(t_p){.y = m[y][x + 1].y, .x = m[y][x + 1].x},
					(t_mlxncolor){.mlx = mlx, .color = m[y][x].rgb});
		}
}
