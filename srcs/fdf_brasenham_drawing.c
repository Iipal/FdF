/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_brasenham_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:09:31 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/28 22:05:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static void	add_bdraw_xline(t_dp delta, t_dp points, t_mlx *mlx, t_g *gradient)
{
	point	p;
	iarr	rgb;
	int		dir;
	int		increase;
	int		i;

	i = ZERO;
	dir = ZERO;
	increase = ZERO;
	p = (t_p) {points.p1.y, points.p1.x};
	rgb = fdf_gradient(gradient, fdf_glen(delta.p1.x, points.p2.x, p.x));
	if (delta.p1.y)
		dir = delta.p1.y > 0 ? 1 : -1;
	while (((delta.p1.x > 0) ? (p.x <= points.p2.x) : (p.x >= points.p2.x)))
	{
		fdf_set_image_pixel(p, rgb[i++], mlx);
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
	iarr	rgb;
	int		dir;
	int		increase;
	int		i;

	i = ZERO;
	dir = ZERO;
	increase = ZERO;
	p = (t_p) {points.p1.y, points.p1.x};
	rgb = fdf_gradient(gradient, fdf_glen(delta.p1.y, points.p2.y, p.y));
	if (delta.p1.y)
		dir = (delta.p1.x > 0 ? 1 : -1);
	while (((delta.p1.y > 0) ? (p.y <= points.p2.y) : (p.y >= points.p2.y)))
	{
		fdf_set_image_pixel(p, rgb[i++], mlx);
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

static void	add_bset_line(t_p dot1, t_p dot2, t_mlx *mlx, t_g gradient)
{
	const int	deltax = dot2.x - dot1.x;
	const int	deltay = dot2.y - dot1.y;
	const int	absdx = _ABS(deltax);
	const int	absdy = _ABS(deltay);

	if (absdx >= absdy)
		add_bdraw_xline((t_dp){{deltay, deltax}, {absdy, absdx}},
						(t_dp){dot1, dot2}, mlx, &gradient);
	else
		add_bdraw_yline((t_dp){{deltay, deltax}, {absdy, absdx}},
						(t_dp){dot1, dot2}, mlx, &gradient);
}

static void	add_bdraw_last_lines(t_matrix **m, t_p mxy, t_mlx mlx, t_p p)
{
	if (p.x == mxy.x - 1 && p.y + 1 < mxy.y)
		add_bset_line((t_p){m[p.y][p.x].y, m[p.y][p.x].x},
			(t_p){m[p.y + 1][p.x].y, m[p.y + 1][p.x].x}, &mlx,
		(t_g){m[p.y][p.x].rgb, m[p.y + 1][p.x].rgb});
	if (p.y == mxy.y - 1 && p.x + 1 < mxy.x)
		add_bset_line((t_p){m[p.y][p.x].y, m[p.y][p.x].x},
			(t_p){m[p.y][p.x + 1].y, m[p.y][p.x + 1].x}, &mlx,
		(t_g){m[p.y][p.x].rgb, m[p.y][p.x + 1].rgb});
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
				add_bset_line((t_p){m[p.y][p.x].y, m[p.y][p.x].x},
					(t_p){.y = m[p.y][p.x + 1].y, m[p.y][p.x + 1].x}, &mlx,
					(t_g){m[p.y][p.x].rgb, m[p.y][p.x + 1].rgb});
				add_bset_line((t_p){.y = m[p.y][p.x].y, m[p.y][p.x].x},
					(t_p){.y = m[p.y + 1][p.x].y, m[p.y + 1][p.x].x}, &mlx,
					(t_g){m[p.y][p.x].rgb, m[p.y + 1][p.x].rgb});
			}
			add_bdraw_last_lines(m, mxy, mlx, p);
		}
}
