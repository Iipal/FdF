/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:47:35 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/18 13:28:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static t_env	*add_alloc_env(string tittle)
{
	t_env	*out_env;

	out_env = (t_env*)malloc(sizeof(t_env));
	*out_env = (t_env){false, 0, 0, 0, 0, IRGB_WHITE, NULL, NULL, NULL, NULL};
	_NOTIS_N(out_env->mlx = mlx_init());
	_NOTIS_N(out_env->win = mlx_new_window(out_env->mlx, WIN_X, WIN_Y, tittle));
	out_env->frog = bonus_init_frog();
	return (out_env);
}

int				main(int argc, char const *argv[])
{
	t_env	*env;

	--argc;
	++argv;
	_NOTIS_MSG("Usage: ./fdf <map_name>", !(!argc || argc > 1));
	_NOTIS_MPE("Where is memory, pal ?", env = add_alloc_env((string)*argv));
	_NOTIS_MPE("File reading error", fdf_file_readnsave_env(*argv, env));
	fdf_rendering(env);
	fdf_key_hooks(&env);
	if (env)
		mlx_loop(env->mlx);
}
