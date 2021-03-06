/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:01:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/17 22:04:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

int			fdf_khook_killwindow(t_env *env)
{
	fdf_free_env(&env);
	exit(EXIT_SUCCESS);
	return (false);
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

static void	add_hook_zoom_projectnzinc(int key, t_env *env)
{
	if (key == PLUS_NUMPAD || key == PLUS_KEYBOARD)
		if ((env->zoom += ZOOM_INC) >= ZOOM_MAX)
			env->zoom = ZOOM_MAX;
	if (key == MINUS_NUMPAD || key == MINUS_KEYBOARD)
		if ((env->zoom -= ZOOM_INC) <= ZOOM_MIN)
			env->zoom = ZOOM_MIN;
	key == KEY_T ? (env->rotx += ROT_INC) : ZERO;
	key == KEY_G ? (env->rotx -= ROT_INC) : ZERO;
	key == KEY_Y ? (env->roty += ROT_INC) : ZERO;
	key == KEY_H ? (env->roty -= ROT_INC) : ZERO;
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
	add_hook_zoom_projectnzinc(key, env);
	fdf_rendering(env);
	return (false);
}
