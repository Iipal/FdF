/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:01:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 18:07:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

int			fdf_khook_close_window(t_env *env)
{
	fdf_free_env(&env);
	exit(1);
	return (0);
}

static void	add_change_color(int *color)
{
	if (*color == IRGB_WHITE)
		*color = IRGB_LIME;
	else if (*color == IRGB_LIME)
		*color = IRGB_CHERRY;
	else if (*color == IRGB_CHERRY)
		*color = IRGB_AQUA;
	else if (*color == IRGB_AQUA)
		*color = IRGB_PINK;
	else if (*color == IRGB_PINK)
		*color = IRGB_ORANGE;
	else if (*color == IRGB_ORANGE)
		*color = IRGB_PURPLE;
	else if (*color == IRGB_PURPLE)
		*color = IRGB_GRAY;
	else
		*color = IRGB_WHITE;
}

static void	add_hook_zoom_projectnrot(int key, t_env *env)
{
	if (key == PLUS_NUMPAD || key == PLUS_KEYBOARD)
		env->zoom + ZOOM_INC <= ZOOM_MAX ? (env->zoom += ZOOM_INC) : false;
	if (key == MINUS_NUMPAD || key == MINUS_KEYBOARD)
		env->zoom - ZOOM_INC >= ZOOM_MIN ? (env->zoom -= ZOOM_INC) : false;
	key == KEY_I && (env->project = P_ISO);
	key == KEY_P && (env->project = P_PAR);
}

int			fdf_keys_hook(int key, t_env *env)
{
	if (key == ESC)
	{
		fdf_free_env(&env);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_D || key == ARROW_RIGHT)
		env->dx += SHIFT_INC;
	if (key == KEY_A || key == ARROW_LEFT)
		env->dx -= SHIFT_INC;
	if (key == KEY_W || key == ARROW_UP)
		env->dy -= SHIFT_INC;
	if (key == KEY_S || key == ARROW_DOWN)
		env->dy += SHIFT_INC;
	if (key == KEY_C)
	{
		add_change_color(&(env->color));
		env->is_frog_render = true;
	}
	else
		env->is_frog_render = false;
	add_hook_zoom_projectnrot(key, env);
	fdf_rendering(env);
	return (0);
}
