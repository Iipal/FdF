/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:01:59 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/20 16:24:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_change_color(int *color, bool *is_render)
{
	*is_render = true;
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

int			fdf_keys_hook(int key, t_env *env)
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
	(key == KEY_C) ? add_change_color(&(env->color), &(env->is_frog_render))
					: (env->is_frog_render = false);
	if (key == PLUS_NUMPAD || key == PLUS_KEYBOARD)
		env->zoom + ZOOM_INC < ZOOM_MAX ? (env->zoom += ZOOM_INC) : false;
	if (key == MINUS_NUMPAD || key == MINUS_KEYBOARD)
		env->zoom - ZOOM_INC > ZOOM_MIN ? (env->zoom -= ZOOM_INC) : false;
	fdf_rendering(env);
	return (0);
}
