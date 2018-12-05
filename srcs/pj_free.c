/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:46:39 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 14:04:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/additional_structs.h"

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

void	pj_mnm_free(t_mnm *mnm)
{
	pj_matrix_free(mnm->m);
	free(mnm);
	mnm = NULL;
}
