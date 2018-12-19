/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:10:47 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/19 10:45:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

void		fdf_free_file(string *file, int lines)
{
	int	i;

	i = NEG;
	while (++i < lines)
		ft_strdel(&(file[i]));
	free(file);
	file = NULL;
}

static void	add_free_frog(int **frog)
{
	int	y;

	y = ZERO;
	while (y < FHEIGHT)
		free(frog[y++]);
	free(frog);
	frog = NULL;
}

void		fdf_free_matrix(t_matrix **m, int matrix_y)
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
	env->frog ? add_free_frog(env->frog) : (env->frog = NULL);
	env->m ? fdf_free_matrix(env->m, env->my) : (env->m = NULL);
	mlx_destroy_window(env->mlx, env->win);
	free(env);
	env = NULL;
}
