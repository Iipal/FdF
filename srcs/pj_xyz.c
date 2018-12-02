/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_xyz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:08:50 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/28 19:08:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pj_matrix_upscale(t_matrix **m, int value)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			m[y][x].x *= value;
			m[y][x].y *= value;
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
			m[y][x].y = (1 / sqrt(6)) + (-ox + 2 * oy + oz);
			m[y][x].z = (1 / sqrt(6)) * (sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz);
		}
}

void	pj_rotare_x(t_matrix **m)
{
	int	oy;
	int oz;
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			oy = m[y][x].y;
			oz = m[y][x].z;
			m[y][x].y = (oy * cos(_RAD(15))) + (oz * sin(_RAD(15)));
			m[y][x].z = (oy * sin(_RAD(15))) + (oz * cos(_RAD(15)));
		}
}

void	pj_rotare_y(t_matrix **m)
{
	int	ox;
	int oz;
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			ox = m[y][x].x;
			oz = m[y][x].z;
			m[y][x].x = (ox * cos(_RAD(15))) + (oz * sin(_RAD(15)));
			m[y][x].z = (ox * sin(_RAD(15))) + (oz * cos(_RAD(15)));
		}
}

void	pj_rotare_z(t_matrix **m)
{
	int	ox;
	int oy;
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			ox = m[y][x].x;
			oy = m[y][x].y;
			m[y][x].x = (ox * cos(_RAD(15))) - (oy * sin(_RAD(15)));
			m[y][x].z = (ox * sin(_RAD(15))) + (oy * cos(_RAD(15)));
		}
}
