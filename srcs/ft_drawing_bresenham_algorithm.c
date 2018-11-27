/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_bresenham_algorithm.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:18:58 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/27 15:19:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/additional_structs.h"

static void	add_draw_line(t_dp delta, t_dp points,
					float *increase, t_mlxncolor mnc)
{
	int	x;
	int	y;
	int	dir;

	dir = ZERO;
	x = points.p1.x;
	y = points.p1.y;
	if (delta.p1.y)
		dir = delta.p1.y > 0 ? 1 : -1;
	while (((delta.p1.x > 0) ? (x <= points.p2.x) : (x >= points.p2.x)))
	{
		mlx_pixel_put(mnc.mlx->mlx, mnc.mlx->win, x, y, mnc.color);
		*increase += (float)delta.p2.y / (float)delta.p2.x;
		if (*increase >= 1.0f)
		{
			*increase -= 1.0f;
			y += dir;
		}
		(delta.p1.x > 0) ? ++x : --x;
	}
}

static void	add_set_line(t_point p1, t_point p2, t_mlxncolor mnc)
{
	const int	deltax = p1.x - p2.x;
	const int	deltay = p1.y - p2.y;
	const int	absdx = _ABS(deltax);
	const int	absdy = _ABS(deltay);
	float		increase;

	increase = ZERO;
	if (absdx >= absdy)
		add_draw_line((t_dp){{p1.x = deltax,
								p1.y = deltay},
							{p2.x = absdx,
								p2.y = absdy}},
					(t_dp){.p1 = p1,
							.p2 = p2},
					&increase, mnc);
	else
		add_draw_line((t_dp){{p1.x = deltay,
								p1.y = deltax},
							{p2.x = absdy,
								p2.y = absdx}},
					(t_dp){.p1 = p2,
							.p2 = p1},
					&increase, mnc);
}

void		pj_mlx_draw_raw_matrix(t_mlx *mlx, t_matrix **matrix)
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
			add_set_line((t_point){.x = x * dist_x, y * dist_y},
						(t_point){.x = (x + 1) * dist_x, y * dist_y},
						(t_mlxncolor){.mlx = mlx, .color = matrix[y][x].z});
			dist_x = DEC;
		}
		dist_y = DEC;
	}
	// mlx_loop(mlx->mlx);
}
