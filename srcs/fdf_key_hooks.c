/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:01:59 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/06 18:19:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_keys_moving(int ket, t_env *env)
{
	if (key == KEY_D)
	{
		mlx_clear_window(env->mlx, env->win);
		add_moving_x(env, MOVE_INC);
		fdf_rendering(env);
	}
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
		mlx_clear_window(env->mlx, env->win);
		fdf_rendering(env);
	}
	if (key == MINUS_NUMPAD || key == MINUS_KEYBOARD)
	{
		(env->zoom - ZOOM_INC >= ZOOM_MIN) ? (env->zoom -= ZOOM_INC) : 0;
		mlx_clear_window(env->mlx, env->win);
		fdf_rendering(env);
	}
	add_keys_moving(key, env);
	return (1);
}

void		fdf_key_hooks(t_env *env)
{
	mlx_hook(env->win, 2, 2, add_keys_hook, env);
}
