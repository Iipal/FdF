/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_matrix_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:13:50 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/04 15:13:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pj_matrix_center(t_matrix **m, uchar grid_zoom)
{
	int	y;
	int	x;
	int	center_y;
	int	center_x;

	y = NEG;
	if (grid_zoom)
		;
	center_y = (WIN_Y / 2) - (((g_matrix_y * grid_zoom) / 2));
	center_x = (WIN_X / 2) - (((g_matrix_x * grid_zoom) / 2));
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			m[y][x].y += center_y;
			m[y][x].x += center_x;
		}
}

void	pj_matrix_upscale(t_matrix **m, uchar upvalue)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			m[y][x].x *= upvalue;
			m[y][x].y *= upvalue;
		}
}

void	pj_isometric(t_matrix **m)
{
	int	ox;
	int oz;
	int oy;
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			ox = m[y][x].x;
			oy = m[y][x].y;
			oz = m[y][x].z;
			m[y][x].x = (1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz);
			m[y][x].y = (1 / sqrt(6)) * (-ox + 2 * oy + oz);
			m[y][x].z = (1 / sqrt(6)) * (sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz);
		}
}
