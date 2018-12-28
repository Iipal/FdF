/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:47:35 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/28 23:36:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static t_env	*add_alloc_env(string tittle)
{
	t_env	*out_env;
	int		bps;
	int		size;
	int		end;

	_NOTIS_N(out_env = (t_env*)malloc(sizeof(t_env)));
	*out_env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL,
		ZOOM_DEF, IRGB_WHITE, ZERO, ZERO, ZERO, ZERO, ZERO,
		ZERO, ZERO, ZERO, ZERO, NULL, false, P_RAW};
	_NOTIS_N(out_env->mlx = mlx_init());
	_NOTIS_N(out_env->win = mlx_new_window(out_env->mlx, WIN_X, WIN_Y, tittle));
	_NOTIS_N(out_env->img = mlx_new_image(out_env->mlx, WIN_X, WIN_Y));
	_NOTIS_N(out_env->screen = (iarr)mlx_get_data_addr(out_env->img,
														&bps, &size, &end));
	out_env->frog = fdf_bonus_init_frog();
	return (out_env);
}

int				main(int argc, char const *argv[])
{
	t_env	*env;

	--argc;
	++argv;
	_NOTIS_MSGN(E_USAGE, !(!argc || argc > 1));
	_NOTIS_MPE(E_ALLOC, env = add_alloc_env((string)*argv));
	_NOTIS_MPE(E_FILER, fdf_file_readnsave_env(*argv, env));
	fdf_rendering(env);
	mlx_hook(env->win, KEY_PRESS, KEY_RELEASE, fdf_keys_hook, env);
	env ? mlx_loop(env->mlx) : false;
}
