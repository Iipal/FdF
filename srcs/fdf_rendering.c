/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/16 11:50:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static void	add_is_render_init(t_isrender *isr, t_env *env)
{
	fdf_add_print_usage();
	*isr = (t_isrender){isr->is_color, env->roty, env->rotx, env->rotz,
				env->zoom, P_PAR, env->dy, env->dx, true, true, isr->is_frog};
	fdf_zooming_buff(env);
	fdf_center_of_buff(env);
}

static void	add_is_refresh_rendering_buff(t_isrender *isr, t_env *env)
{
	if (isr->is_zoom != env->zoom)
		isr->is_refresh_buff = true;
	if (isr->is_project != env->project)
		isr->is_refresh_buff = true;
	if (isr->is_shiftx != env->dx && (isr->is_refresh_buff = true))
		fdf_move_buff(env, ((env->dx > isr->is_shiftx) ? SHIFT_INC : -SHIFT_INC), ZERO);
	if (isr->is_shifty != env->dy && (isr->is_refresh_buff = true))
		fdf_move_buff(env, ZERO, ((env->dy > isr->is_shifty) ? SHIFT_INC : -SHIFT_INC));
	if (isr->is_rotx != env->rotx && (isr->is_refresh_buff = true))
	{
		(env->rotx > ROT_MAX) ? (env->rotx -= ROT_MAX) : ZERO;
		(env->rotx < ROT_MIN) ? (env->rotx += ROT_MAX) : ZERO;
	}
	if (isr->is_roty != env->roty && (isr->is_refresh_buff = true))
	{
		(env->roty > ROT_MAX) ? (env->roty -= ROT_MAX) : ZERO;
		(env->roty < ROT_MIN) ? (env->roty += ROT_MAX) : ZERO;
	}
	if (isr->is_rotz != env->rotz && (isr->is_refresh_buff = true))
	{
		(env->rotz > ROT_MAX) ? (env->rotz -= ROT_MAX) : ZERO;
		(env->rotz < ROT_MIN) ? (env->rotz += ROT_MAX) : ZERO;
	}
}

void		fdf_rendering(t_env *env)
{
	static t_isrender	isr;

	printf("%lu\n", sizeof(t_isrender));
	isr.is_refresh_buff = false;
	if (!env->render)
		if (!fdf_init_render_buff(env))
			exit(EXIT_SUCCESS);
	env->frog ? (isr.is_frog = true) : false;
	(!isr.is_init) ? add_is_render_init(&isr, env) : NULL;
	add_is_refresh_rendering_buff(&isr, env);
	fdf_is_render_frog(&isr, env);
	if (isr.is_refresh_buff)
	{
		fdf_refresh_buff(env, &isr);
		fdf_refresh_image(env);
		if (env->is_frog_render)
			fdf_print_fucking_frog(env);
	}
}
