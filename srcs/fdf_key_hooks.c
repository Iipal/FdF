/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:01:59 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/08 18:25:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_keys_movenrotare(int key, t_env *env)
{
	if (key == KEY_D || key == ARROW_RIGHT)
		fdf_xmove(env, MOVE_INC);
	if (key == KEY_A || key == ARROW_LEFT)
		fdf_xmove(env, -MOVE_INC);
	if (key == KEY_W || key == ARROW_UP)
		fdf_ymove(env, -MOVE_INC);
	if (key == KEY_S || key == ARROW_DOWN)
		fdf_ymove(env, MOVE_INC);
	if (key == KEY_R)
		fdf_xrotare(env, ROT_INC);
	if (key == KEY_F)
		fdf_xrotare(env, -ROT_INC);
}

static int	add_keys_hook(int key, t_env *env)
{
	if (key == ESC)
	{
		fdf_free_env(env);
		exit(EXIT_SUCCESS);
	}
	if (key == PLUS_NUMPAD || key == PLUS_KEYBOARD)
	{
		(env->zoom + ZOOM_INC <= ZOOM_MAX) ? (env->zoom += ZOOM_INC) : 0;
		fdf_rendering(env);
	}
	if (key == MINUS_NUMPAD || key == MINUS_KEYBOARD)
	{
		(env->zoom - ZOOM_INC >= ZOOM_MIN) ? (env->zoom -= ZOOM_INC) : 0;
		fdf_rendering(env);
	}
	add_keys_movenrotare(key, env);
	return (1);
}

void		fdf_key_hooks(t_env *env)
{
	mlx_hook(env->win, 2, 2, add_keys_hook, env);
}
