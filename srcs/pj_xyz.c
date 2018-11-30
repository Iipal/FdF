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

void		pj_appscale_xy(t_matrix **m, int value)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			m[y][x].y *= value;
			m[y][x].x *= value;
		}

}

void		pj_rotare_xyz(t_matrix **m)
{
	int x1;
	int y1;
	int z1;
	int	x0;
	int	y0;
	int	z0;
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
		while (++x < g_matrix_x)
		{
			x0 = m[y][x].x;
			y0 = m[y][x].y * cos(25) + m[y][x].z * sin(25);
			z0 = m[y][x].z * cos(25) - m[y][x].y * sin(25);
			x1 = x0 * cos(0) - x0 * sin(0);
			y1 = y0;
			z1 = z0 * cos(0) - x0 * sin(0);
			m[y][x].x = x1 * cos(0) + y1 * sin(0);
			m[y][x].y = y1 * cos(0) - x1 * sin(0);
		}
}
