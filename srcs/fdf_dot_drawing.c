/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dot_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:31:06 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/19 10:23:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_dot_drawing(t_matrix **m, t_p mxy, t_mlx mlx)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < mxy.y && (x = NEG))
		while (++x < mxy.x)
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, m[y][x].rgb);
}
