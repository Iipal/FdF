/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:10:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/17 10:58:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

void		fdf_free_file(strtab *file, int lines)
{
	int	i;

	i = NEG;
	while (++i < lines)
		free((*file)[i]);
	free(*file);
	*file = NULL;
}

static void	add_free_frog(itab *frog)
{
	int	y;

	y = ZERO;
	while (y < FHEIGHT)
		free((*frog)[y++]);
	free(*frog);
	*frog = NULL;
}

void		fdf_free_matrix(t_matrix ***m, int matrix_y)
{
	int	y;

	y = NEG;
	while (++y < matrix_y)
		free((*m)[y]);
	free(*m);
	*m = NULL;
}

void		fdf_free_env(t_env **env)
{
	(*env)->buff ? fdf_free_matrix(&((*env)->buff), (*env)->my) : NULL;
	(*env)->raw ? fdf_free_matrix(&((*env)->raw), (*env)->my) : NULL;
	(*env)->frog ? add_free_frog(&(*env)->frog) : NULL;
	(*env)->img ? mlx_destroy_image((*env)->mlx, (*env)->img) : ZERO;
	mlx_destroy_window((*env)->mlx, (*env)->win);
	free(*env);
	*env = NULL;
}
