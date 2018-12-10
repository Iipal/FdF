/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:01:59 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/10 15:28:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_keys_movenrotare(int key, t_env *env)
{
	if (key == KEY_D || key == ARROW_RIGHT)
		env->shift_x += SHIFT_INC;
		// fdf_xmove(env, SHIFT_INC);
	if (key == KEY_A || key == ARROW_LEFT)
		env->shift_x -= SHIFT_INC;
		// fdf_xmove(env, -SHIFT_INC);
	if (key == KEY_W || key == ARROW_UP)
		env->shift_y -= SHIFT_INC;
		// fdf_ymove(env, -SHIFT_INC);
	if (key == KEY_S || key == ARROW_DOWN)
		fdf_ymove(env, MOVE_INC);
	if (key == KEY_R)
		fdf_xrotare(env, ROT_INC);
	if (key == KEY_F)
		fdf_xrotare(env, -ROT_INC);
	if (key == KEY_T)
		fdf_yrotare(env, ROT_INC);
	if (key == KEY_G)
		fdf_yrotare(env, -ROT_INC);
	if (key == KEY_Y)
		fdf_zrotare(env, ROT_INC);
	if (key == KEY_H)
		fdf_zrotare(env, -ROT_INC);
}

static int	add_keys_hook(int key, t_env *env)
{
	if (key == ESC)
	{
		fdf_free_env(env);
		exit(EXIT_SUCCESS);
	}
	if (key == PLUS_NUMPAD || key == PLUS_KEYBOARD)
		(env->zoom + ZOOM_INC <= ZOOM_MAX) ? (env->zoom += ZOOM_INC) : 0;
	if (key == MINUS_NUMPAD || key == MINUS_KEYBOARD)
		(env->zoom - ZOOM_INC >= ZOOM_MIN) ? (env->zoom -= ZOOM_INC) : 0;
	add_keys_movenrotare(key, env);
	fdf_rendering(env);
	return (1);
}

void		fdf_key_hooks(t_env *env)
{
	mlx_hook(env->win, 2, 2, add_keys_hook, env);
}
