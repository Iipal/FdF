/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_brasenham_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:09:31 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/11 20:29:04 by tmaluh           ###   ########.fr       */
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

bool	add_is_view(t_p dot)
{
	if (dot.x > WIN_X || dot.x < 0)
		return (false);
	if (dot.y > WIN_Y || dot.y < 0)
		return (false);
	return (true);
}

void		fdf_bdrawing(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			if ((x + 1 < env->mx) && (y + 1 < env->my))
			{
				add_bset_line((t_p){.y = env->m[y][x].y * env->zoom + env->shift_y, .x = env->m[y][x].x * env->zoom + env->shift_x},
					(t_p){.y = env->m[y][x + 1].y * env->zoom + env->shift_y, .x = env->m[y][x + 1].x * env->zoom + env->shift_x},
				(t_mnc){.mlx = env->mlx, .win = env->win, .color = env->m[y][x].rgb});
				add_bset_line((t_p){.y = env->m[y][x].y * env->zoom + env->shift_y, .x = env->m[y][x].x * env->zoom + env->shift_x},
							(t_p){.y = env->m[y + 1][x].y * env->zoom + env->shift_y, .x = env->m[y + 1][x].x * env->zoom + env->shift_x},
				(t_mnc){.mlx = env->mlx, .win = env->win, .color = env->m[y][x].rgb});
			}
			else if (x == env->mx - 1 && y + 1 < env->my)
				add_bset_line((t_p){.y = env->m[y][x].y * env->zoom + env->shift_y, .x = env->m[y][x].x * env->zoom + env->shift_x},
							(t_p){.y = env->m[y + 1][x].y * env->zoom + env->shift_y, .x = env->m[y + 1][x].x * env->zoom + env->shift_x},
				(t_mnc){.mlx = env->mlx, .win = env->win, .color = env->m[y][x].rgb});
			else if (y == env->my - 1 && x + 1 < env->mx)
				add_bset_line((t_p){.y = env->m[y][x].y * env->zoom + env->shift_y, .x = env->m[y][x].x * env->zoom + env->shift_x},
							(t_p){.y = env->m[y][x + 1].y * env->zoom + env->shift_y, .x = env->m[y][x + 1].x * env->zoom + env->shift_x},
				(t_mnc){.mlx = env->mlx, .win = env->win, .color = env->m[y][x].rgb});
		}
}
