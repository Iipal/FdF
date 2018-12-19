/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dot_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:31:06 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/19 13:49:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_dot_drawing(t_matrix **m, t_p mxy, t_mlx mlx)
{
	int	y;
	int	x;

	y = NEG;
	_WHILE(y, x, mxy.y, mxy.x)
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, m[y][x].rgb);
}
