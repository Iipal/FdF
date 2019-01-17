/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:40:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/17 22:06:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_mouse_press(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == MSCROLL_UPS)
	{
		if ((env->zoom += ZOOM_INC) >= ZOOM_MAX)
			env->zoom = ZOOM_MAX;
	}
	else if (button == MSCROLL_DOWN)
	{
		if ((env->zoom -= ZOOM_INC) <= ZOOM_MIN)
			env->zoom = ZOOM_MIN;
	}
	else if (button == MLEFT_BUTTON)
		env->mouse.pres = true;
	fdf_rendering(env);
	return (false);
}

int		fdf_mouse_release(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	(void)button;
	env->mouse.pres = false;
	return (false);
}

int		fdf_mouse_moves(int x, int y, t_env *env)
{
	env->mouse.last.x = env->mouse.curr.x;
	env->mouse.last.y = env->mouse.curr.y;
	env->mouse.curr.x = x;
	env->mouse.curr.y = y;
	if (env->mouse.pres)
	{
		env->rotx -= (y - env->mouse.last.y) * 0.2;
		env->roty += (x - env->mouse.last.x) * 0.2;
		fdf_rendering(env);
	}
	return (false);
}
