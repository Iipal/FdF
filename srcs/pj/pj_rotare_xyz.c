/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_rotare_xyz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:08:50 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/28 19:08:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	add_rotare_y(t_matrix **m, int value)
{
	int	oy;
	int	oz;
	int	y;
	int	x;

	if (value)
		;
	y = NEG;
	while (++y < g_matrix_y)
	{
		x = NEG;
		while (++x < g_matrix_x)
		{
			oy = m[y][x].y;
			oz = m[y][x].z;
			m[y][x].y = m[y][x].x + (m[y][x].x * cos(35)) + (oz * sin(0));
			m[y][x].z = m[y][x].z + (m[y][x].x * sin(35)) + (oz * cos(35));
		}
	}
}

void		pj_rotare_xyz(t_matrix **m)
{
	add_rotare_y(m, 1);
}


/*x, y, z - координаты точки
x', y', z' - новые координаты точки
sin(A), cos(A), tan(A) - синус, косинус и тангенс угла A 

- вокруг оси X
x' = x;
y' = y0+(y-y0)*cos(A)+(z0-z)*sin(alpha);
z' = z0+(y-y0)*sin(A)+(z-z0)*cos(alpha);

- вокруг оси Y
x' = x0+(x-x0)*cos(A)+(z-z0)*sin(alpha);
y' = y;
z' = z0+(x0-x)*sin(A)+(z-z0)*cos(alpha);

- вокруг оси Z
x' = x0+(x-x0)*cos(A)+(y0-y)*sin(alpha);
y' = y0+(x-x0)*sin(A)+(y-y0)*cos(alpha);
z' = z;
*/