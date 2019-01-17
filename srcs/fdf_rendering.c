/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/17 10:56:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static void	add_is_refresh_rendering_buff(t_env *env)
{
	if (env->isr.is_zoom != env->zoom)
		env->isr.is_refresh_buff = true;
	if (env->isr.is_project != env->project)
		env->isr.is_refresh_buff = true;
	if (env->isr.is_shiftx != env->dx && (env->isr.is_refresh_buff = true))
		fdf_move_buff(env, ((env->dx > env->isr.is_shiftx)
							? SHIFT_INC : -SHIFT_INC), ZERO);
	if (env->isr.is_shifty != env->dy && (env->isr.is_refresh_buff = true))
		fdf_move_buff(env, ZERO, ((env->dy > env->isr.is_shifty)
							? SHIFT_INC : -SHIFT_INC));
	if (env->isr.is_rotx != env->rotx && (env->isr.is_refresh_buff = true))
	{
		(env->rotx >= ROT_MAX) ? (env->rotx -= ROT_MAX) : ZERO;
		(env->rotx <= ROT_MIN) ? (env->rotx += ROT_MAX) : ZERO;
	}
	if (env->isr.is_roty != env->roty && (env->isr.is_refresh_buff = true))
	{
		(env->roty >= ROT_MAX) ? (env->roty -= ROT_MAX) : ZERO;
		(env->roty <= ROT_MIN) ? (env->roty += ROT_MAX) : ZERO;
	}
}

void		fdf_rendering(t_env *env)
{
	add_is_refresh_rendering_buff(env);
	fdf_is_render_frog(env);
	if (env->isr.is_refresh_buff)
	{
		fdf_refresh_buff(env);
		fdf_refresh_image(env);
		if (env->is_frog_render)
			fdf_print_fucking_frog(env);
	}
}
