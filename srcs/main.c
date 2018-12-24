/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:47:35 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/24 10:53:16 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static t_env	*add_alloc_env(string tittle)
{
	t_env	*out_env;

	_NOTIS_N(out_env = (t_env*)malloc(sizeof(t_env)));
	*out_env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL, ZOOM_DEF,
			IRGB_WHITE, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, false, P_RAW};
	_NOTIS_N(out_env->mlx = mlx_init());
	_NOTIS_N(out_env->win = mlx_new_window(out_env->mlx, WIN_X, WIN_Y, tittle));
	_NOTIS_N(out_env->img = mlx_new_image(out_env->mlx, WIN_X, WIN_Y));
	out_env->frog = fdf_bonus_init_frog();
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
	mlx_hook(env->win, KEY_PRESS, KEY_MASK, fdf_keys_hook, env);
	env ? mlx_loop(env->mlx) : false;
}
