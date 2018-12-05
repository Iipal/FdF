/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:57:48 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 14:33:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	pj_render(t_mlx *mlx, t_matrix **matrix, uchar grid_size)
{
	// t_matrix **changed;

	pj_matrix_upscale(matrix, grid_size);
	// pj_matrix_isometric(changed);
	// _NOTIS_F(changed = pj_matrix_new_centralize(matrix, grid_size));
	pj_drawing_brasenham(mlx, matrix);
	pj_key_pressed(mlx, matrix);
	return (true);
}
