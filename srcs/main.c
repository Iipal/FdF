/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:47:35 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/13 10:34:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_env	*add_alloc_env(string tittle)
{
	t_env	*out;

	out = (t_env*)malloc(sizeof(t_env));
	*out = (t_env){0, 0, 0, 0, IRGB_WHITE, ZOOM_DEF, NULL, NULL, NULL, NULL};
	_NOTIS_N(out->mlx = mlx_init());
	_NOTIS_N(out->win = mlx_new_window(out->mlx, WIN_X, WIN_Y, tittle));
	return (out);
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
	fdf_key_hooks(env);
	mlx_loop(env->mlx);
}
