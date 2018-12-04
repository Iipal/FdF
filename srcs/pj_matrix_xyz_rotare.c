/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_matrix_xyz_rotare.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:08:50 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/28 19:08:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			m[y][x].y = (oy * cos(_RAD(10))) + (oz * sin(_RAD(10)));
			m[y][x].z = (oy * sin(_RAD(10))) + (oz * cos(_RAD(10)));
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
			m[y][x].x = (ox * cos(_RAD(-90))) + (oz * sin(_RAD(-90)));
			m[y][x].z = (ox * sin(_RAD(-90))) + (oz * cos(_RAD(-90)));
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
