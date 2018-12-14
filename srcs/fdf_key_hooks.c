/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:01:59 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/14 14:13:23 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_change_color(int *color)
{
	if (*color == IRGB_WHITE)
		*color = IRGB_LIME;
	else if (*color == IRGB_LIME)
		*color = IRGB_CHERRY;
	else if (*color == IRGB_CHERRY)
		*color = IRGB_AQUA;
	else if (*color == IRGB_AQUA)
		*color = IRGB_GRAY;
	else
		*color = IRGB_WHITE;
}

static void	add_keys_movenrotare(int key, t_env *env)
{
	/*if (key == KEY_R)
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
		fdf_zrotare(env, -ROT_INC);*/
	if (key == KEY_C)
		add_change_color(&(env->color));
}

static int	add_keys_hook(int key, t_env *env)
{
	if (key == ESC)
	{
		fdf_free_env(env);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_D || key == ARROW_RIGHT)
		env->sx += SHIFT_INC;
	if (key == KEY_A || key == ARROW_LEFT)
		env->sx -= SHIFT_INC;
	if (key == KEY_W || key == ARROW_UP)
		env->sy -= SHIFT_INC;
	if (key == KEY_S || key == ARROW_DOWN)
		env->sy += SHIFT_INC;
	add_keys_movenrotare(key, env);
	fdf_rendering(env);
	return (0);
}

void		fdf_key_hooks(t_env *env)
{
	mlx_hook(env->win, KEY_PRESS, KEY_MASK, add_keys_hook, env);
}
