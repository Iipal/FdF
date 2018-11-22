/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:37:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/22 15:37:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pj_free_file(t_file **file)
{
	size_t	i;

	i = ZERO;
	while (i < ((*file)->lines))
		ft_strdel(&((*file)->tab[i++]));
	free((*file)->tab);
	free(*file);
	file = NULL;
}

void	pj_free_matrix(t_matrix **matrix)
{
	size_t	i;

	i = ZERO;
	while (i < g_matrix_y)
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}
