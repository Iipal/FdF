/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_brasenham_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:09:31 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/21 23:58:32 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_bdraw_xline(t_dp delta, t_dp points, t_mlx *mlx, t_g *gradient)
{
	point	p;
	int		dir;
	int		increase;
	int		*rgb;
	int		i;

	i = ZERO;
	dir = ZERO;
	p.y = points.p1.y;
	p.x = points.p1.x;
	increase = ZERO;
	rgb = fdf_bdrawing_gradient(*gradient,
		fdf_find_gradient_len(delta.p1.x, points.p2.x, p.x));
	if (delta.p1.y)
		dir = delta.p1.y > 0 ? 1 : -1;
	while (((delta.p1.x > 0) ? (p.x <= points.p2.x) : (p.x >= points.p2.x)))
	{
		mlx_pixel_put(mlx->mlx, mlx->win, p.x, p.y, rgb[i++]);
		increase += delta.p2.y;
		if (increase >= delta.p2.x)
		{
			increase -= delta.p2.x;
			p.y += dir;
		}
		(delta.p1.x > 0) ? ++(p.x) : --(p.x);
	}
	free(rgb);
}

static void	add_bdraw_yline(t_dp delta, t_dp points, t_mlx *mlx, t_g *gradient)
{
	point	p;
	int		dir;
	int		increase;
	int		*rgb;
	int		i;

	i = ZERO;
	dir = ZERO;
	p.y = points.p1.y;
	p.x = points.p1.x;
	increase = ZERO;
	rgb = fdf_bdrawing_gradient(*gradient,
		fdf_find_gradient_len(delta.p1.y, points.p2.y, p.y));
	if (delta.p1.y)
		dir = (delta.p1.x > 0 ? 1 : -1);
	while (((delta.p1.y > 0) ? (p.y <= points.p2.y) : (p.y >= points.p2.y)))
	{
		mlx_pixel_put(mlx->mlx, mlx->win, p.x, p.y, rgb[i++]);
		increase += delta.p2.x;
		if (increase >= delta.p2.y)
		{
			increase -= delta.p2.y;
			p.x += dir;
		}
		(delta.p1.y > 0) ? ++(p.y) : --(p.y);
	}
	free(rgb);
}

static void	add_bset_line(t_p dot1, t_p dot2, t_mlx mlx, t_g gradient)
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
					(t_dp){.p1 = dot1, .p2 = dot2}, &mlx, &gradient);
	else
		add_bdraw_yline((t_dp){.p1.x = deltax,
								.p1.y = deltay,
								.p2.x = absdx,
								.p2.y = absdy},
					(t_dp){.p1 = dot1, .p2 = dot2}, &mlx, &gradient);
}

static void	add_blast_lines(t_matrix **m, t_p mxy, t_mlx mlx, t_p p)
{
	if (p.x == mxy.x - 1 && p.y + 1 < mxy.y)
		add_bset_line((t_p){.y = m[p.y][p.x].y, .x = m[p.y][p.x].x},
			(t_p){.y = m[p.y + 1][p.x].y, .x = m[p.y + 1][p.x].x},
						(t_mlx){.mlx = mlx.mlx, .win = mlx.win},
		(t_g){.start = m[p.y][p.x].rgb, .end = m[p.y + 1][p.x].rgb});
	if (p.y == mxy.y - 1 && p.x + 1 < mxy.x)
		add_bset_line((t_p){.y = m[p.y][p.x].y, .x = m[p.y][p.x].x},
			(t_p){.y = m[p.y][p.x + 1].y, .x = m[p.y][p.x + 1].x},
						(t_mlx){.mlx = mlx.mlx, .win = mlx.win},
		(t_g){.start = m[p.y][p.x].rgb, .end = m[p.y][p.x + 1].rgb});
}

void		fdf_bdrawing(t_matrix **m, t_p mxy, t_mlx mlx)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < mxy.y && (p.x = NEG))
		while (++(p.x) < mxy.x)
		{
			if ((p.x + 1 < mxy.x) && (p.y + 1 < mxy.y))
			{
				add_bset_line((t_p){.y = m[p.y][p.x].y, .x = m[p.y][p.x].x},
					(t_p){.y = m[p.y][p.x + 1].y, .x = m[p.y][p.x + 1].x},
								(t_mlx){.mlx = mlx.mlx, .win = mlx.win},
				(t_g){.start = m[p.y][p.x].rgb, .end = m[p.y][p.x + 1].rgb});
				add_bset_line((t_p){.y = m[p.y][p.x].y, .x = m[p.y][p.x].x},
					(t_p){.y = m[p.y + 1][p.x].y, .x = m[p.y + 1][p.x].x},
								(t_mlx){.mlx = mlx.mlx, .win = mlx.win},
				(t_g){.start = m[p.y][p.x].rgb, .end = m[p.y + 1][p.x].rgb});
			}
			add_blast_lines(m, mxy, mlx, p);
		}
}
