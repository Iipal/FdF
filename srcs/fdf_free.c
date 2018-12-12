/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:10:47 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/12 15:11:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	File with all "free" functions.
**		'fdf_free_file' - Free "file". About "file":
**			| - Created in 'fdf_file_readnsave_env'. (fdf_readnsave.c)
**			| - Including in 'add_save_tomatrix'. (fdf_readnsave.c)
*/

void		fdf_free_file(string *file, int lines)
{
	int	i;

	i = NEG;
	while (++i < lines)
		ft_strdel(&(file[i]));
	free(file);
	file = NULL;
}

static void	fdf_free_matrix(t_matrix **m, int matrix_y)
{
	int	y;

	y = NEG;
	while (++y < matrix_y)
		free(m[y]);
	free(m);
	m = NULL;
}

void		fdf_free_env(t_env *env)
{
	fdf_free_matrix(env->m, env->my);
	// fdf_free_matrix(env->buff, env->my);
	mlx_destroy_window(env->mlx, env->win);
	free(env);
	env = NULL;
}
