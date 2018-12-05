/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_matrix_modification.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:13:50 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 14:28:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix	**pj_matrix_new_centralize(t_matrix **m, uchar grid_zoom)
{
	t_matrix	**out;
	int			center_y;
	int			center_x;
	int			y;
	int			x;

	y = NEG;
	_NOTIS_N(out = (t_matrix**)malloc(sizeof(t_matrix*) * g_matrix_y));
	while (++y < g_matrix_y)
		_NOTIS_N(out[y] = (t_matrix*)malloc(sizeof(t_matrix) * g_matrix_x));
	center_y = (g_matrix_y / 2) * grid_zoom;
	center_x = (g_matrix_x / 2) * grid_zoom;
	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			out[y][x].y = center_y - WIN_Y / 2;
			out[y][x].x = center_x - WIN_X / 2;
			out[y][x].z = m[y][x].z;
			out[y][x].rgb = m[y][x].rgb;
		}
	return (out);
}

void		pj_matrix_upscale(t_matrix **m, uchar upvalue)
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

void		pj_matrix_isometric(t_matrix **m)
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
			m[y][x].z = (1 / sqrt(6)) *
						(sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz);
		}
}
