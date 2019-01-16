/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:47:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/16 22:47:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static t_env	*add_alloc_env(string tittle)
{
	t_env	*env;
	int		bps;
	int		sz;
	int		end;

	_NOTIS_N(env = (t_env*)malloc(sizeof(t_env)));
	*env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL, ZOOM_DEF, IRGB_WHITE,
		ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, ZERO, {ZERO, ZERO, ZERO},
		NULL, false, P_PAR};
	_NOTIS_N(env->mlx = mlx_init());
	_NOTIS_N(env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, tittle));
	_NOTIS_N(env->img = mlx_new_image(env->mlx, WIN_X, WIN_Y));
	_NOTIS_N(env->screen = (iarr)mlx_get_data_addr(env->img, &bps, &sz, &end));
	env->frog = fdf_bonus_init_frog();
	return (env);
}

int				main(int argc, char const *argv[])
{
	t_env	*env;

	--argc;
	++argv;
	_NOTIS_MSGN(E_USAGE, !(!argc || argc > 1));
	_NOTIS_MPE(E_ALLOC, env = add_alloc_env((string)*argv));
	_NOTIS_MPE(E_FILER, fdf_file_readnsave_env(*argv, env));
	fdf_add_colored_map(env);
	fdf_rendering(env);
	mlx_hook(env->win, WIN_EXIT, WIN_EXIT_MASK, fdf_khook_close_window, env);
	mlx_hook(env->win, KEY_PRESS, KEY_RELEASE, fdf_keys_hook, env);
	env ? mlx_loop(env->mlx) : false;
}
