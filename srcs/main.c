/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:47:35 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/11 13:47:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static bool	add_alloc_env(string tittle, t_env *env)
{
	env->zoom = ZOOM_DEF;
	env->matrix_y = ZERO;
	env->matrix_x = ZERO;
	env->shift_y = ZERO;
	env->shift_x = ZERO;
	env->buff = NULL;
	_NOTIS_F(env->mlx = mlx_init());
	_NOTIS_F(env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, tittle));
	return (true);
}

int		main(int argc, char const *argv[])
{
	t_env	*env;

	--argc;
	++argv;
	_NOTIS_MPE("Where is memory, pal ?", env = (t_env*)malloc(sizeof(t_env)));
	_NOTIS_MSG("Failed MLX init.", add_alloc_env((string)*argv, env));
	_NOTIS_MSG("Usage: ./fdf <map_name>", !(!argc || argc > 1));
	_NOTIS_MPE("File reading error", fdf_file_readnsave_env(*argv, env));
	_NOTIS_MSG("Rendering error.", fdf_rendering(env));
	fdf_key_hooks(env);
	mlx_loop(env->mlx);
}
