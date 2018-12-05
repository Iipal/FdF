/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:57:48 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/04 14:57:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pj_render(t_mlx *mlx, t_matrix **matrix, uchar grid_size)
{
	pj_matrix_upscale(matrix, grid_size);
	// pj_matrix_isometric(matrix);
	pj_matrix_find_center(matrix, grid_size);
	pj_drawing_brasenham(mlx, matrix);
}
