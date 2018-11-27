/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:46:39 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/25 18:30:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pj_file_free(string *file)
{
	int	i;

	i = NEG;
	while (++i < g_matrix_y)
		ft_strdel(&(file[i]));
	free(file);
	file = NULL;
}

void	pj_matrix_free(t_matrix **matrix)
{
	int	i;

	i = NEG;
	while (++i < g_matrix_y)
		free(matrix[i]);
	free(matrix);
	matrix = NULL;
}

void	pj_mlx_free(t_mlx *mlx)
{
	free(mlx->mlx);
	free(mlx->win);
	free(mlx);
	mlx = NULL;
}
