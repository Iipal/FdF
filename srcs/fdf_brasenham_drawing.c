/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_brasenham_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:09:31 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/13 10:38:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_bdraw_xline(t_dp delta, t_dp points, t_mnc mnc)
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
		mlx_pixel_put(mnc.mlx, mnc.win, x, y, mnc.color);
		increase += delta.p2.y;
		if (increase >= delta.p2.x)
		{
			increase -= delta.p2.x;
			y += dir;
		}
		(delta.p1.x > 0) ? ++x : --x;
	}
}

static void	add_bdraw_yline(t_dp delta, t_dp points, t_mnc mnc)
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
		mlx_pixel_put(mnc.mlx, mnc.win, x, y, mnc.color);
		increase += delta.p2.x;
		if (increase >= delta.p2.y)
		{
			increase -= delta.p2.y;
			x += dir;
		}
		(delta.p1.y > 0) ? ++y : --y;
	}
}

static void	add_bset_line(t_p dot1, t_p dot2, t_mnc mnc)
{
	const int	deltax = dot2.x - dot1.x;
	const int	deltay = dot2.y - dot1.y;
	const int	absdx = _ABS(deltax);
	const int	absdy = _ABS(deltay);

	if (absdx >= absdy)
		add_bdraw_xline((t_dp){.p1.x = deltax,
								.p1.y = deltay,
								.p2.x = absdx,
								.p2.y = absdy},
					(t_dp){.p1 = dot1, .p2 = dot2}, mnc);
	else
		add_bdraw_yline((t_dp){.p1.x = deltax,
								.p1.y = deltay,
								.p2.x = absdx,
								.p2.y = absdy},
					(t_dp){.p1 = dot1, .p2 = dot2}, mnc);
}

void		fdf_bdrawing(t_matrix **m, t_p mxy, t_mlx mlx)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < mxy.y && (x = NEG))
		while (++x < mxy.x)
		{
			if ((x + 1 < mxy.x) && (y + 1 < mxy.y))
			{
				add_bset_line((t_p){.y = m[y][x].y, .x = m[y][x].x},
					(t_p){.y = m[y][x + 1].y, .x = m[y][x + 1].x},
				(t_mnc){.mlx = mlx.mlx, .win = mlx.win, .color = m[y][x].rgb});
				add_bset_line((t_p){.y = m[y][x].y, .x = m[y][x].x},
							(t_p){.y = m[y + 1][x].y, .x = m[y + 1][x].x},
				(t_mnc){.mlx = mlx.mlx, .win = mlx.win, .color = m[y][x].rgb});
			}
			else if (x == mxy.x - 1 && y + 1 < mxy.y)
				add_bset_line((t_p){.y = m[y][x].y, .x = m[y][x].x},
							(t_p){.y = m[y + 1][x].y, .x = m[y + 1][x].x},
				(t_mnc){.mlx = mlx.mlx, .win = mlx.win, .color = m[y][x].rgb});
			else if (y == mxy.y - 1 && x + 1 < mxy.x)
				add_bset_line((t_p){.y = m[y][x].y, .x = m[y][x].x},
							(t_p){.y = m[y][x + 1].y, .x = m[y][x + 1].x},
				(t_mnc){.mlx = mlx.mlx, .win = mlx.win, .color = m[y][x].rgb});
		}
}
