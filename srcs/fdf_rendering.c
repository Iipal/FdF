/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/28 23:39:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static void	add_init_centralize(t_env *env)
{
	point	p;

	p.y = NEG;
	env->sy = ((WIN_Y - ((env->my - 1.0) * env->zoom)) / 2);
	env->sx = ((WIN_X - ((env->mx - 1.0) * env->zoom)) / 2);
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			env->render[p.y][p.x].y += env->sy;
			env->render[p.y][p.x].x += env->sx;
		}
}

static void	add_is_render_init(t_isrender *isr, t_env *env)
{
	fdf_add_print_usage();
	if (fdf_add_check_valid_perspective(env))
		isr->is_perspective = true;
	isr->is_roty = env->roty;
	isr->is_rotx = env->rotx;
	isr->is_rotz = env->rotz;
	isr->is_shiftx = env->dx;
	isr->is_shifty = env->dy;
	isr->is_isr_init = true;
	isr->is_project = P_RAW;
}

static void	add_is_render_rot(t_isrender *isr, t_env *env)
{
	if (isr->is_rotx != env->rotx && (isr->is_render = true))
	{
		(env->rotx == ROT_MAX) ? (env->rotx = ROT_MIN) : ZERO;
		(env->rotx > ROT_MAX) ? (env->rotx -= ROT_MAX) : ZERO;
		(env->rotx < ROT_MIN) ? (env->rotx += ROT_MAX) : ZERO;
		fdf_refresh_buff(env, isr);
		printf("x: %.2f\n", env->rotx);
	}
	if (isr->is_roty != env->roty && (isr->is_render = true))
	{
		(env->roty == ROT_MAX) ? (env->roty = ROT_MIN) : ZERO;
		(env->roty > ROT_MAX) ? (env->roty -= ROT_MAX) : ZERO;
		(env->roty < ROT_MIN) ? (env->roty += ROT_MAX) : ZERO;
		fdf_refresh_buff(env, isr);
		printf("y: %.2f\n", env->roty);
	}
	if (isr->is_rotz != env->rotz && (isr->is_render = true))
	{
		(env->rotz == ROT_MAX) ? (env->rotz = ROT_MIN) : ZERO;
		(env->rotz > ROT_MAX) ? (env->rotz -= ROT_MAX) : ZERO;
		(env->rotz < ROT_MIN) ? (env->rotz += ROT_MAX) : ZERO;
		fdf_refresh_buff(env, isr);
		printf("z: %.2f\n", env->rotz);
	}
}

static void	add_is_render(t_isrender *isr, t_env *env)
{
	isr->is_render = false;
	if ((!isr->is_zoomed) ? (isr->is_zoomed = env->zoom) : false)
		fdf_zooming(env);
	else if (isr->is_zoomed != env->zoom && (isr->is_render = true))
		fdf_refresh_buff(env, isr);
	if (isr->is_project != env->project && (isr->is_render = true))
	{
		isr->is_project = env->project;
		env->project == P_ISO ? fdf_refresh_buff(env, isr) : false;
		env->project == P_PER ? fdf_refresh_buff(env, isr) : false;
		env->project == P_RAW ? fdf_refresh_buff(env, isr) : false;
	}
	if ((!isr->is_center ? (isr->is_center = true) : false)
			&& (isr->is_render = true))
		add_init_centralize(env);
	if (isr->is_shiftx != env->dx && (isr->is_render = true))
	{
		fdf_xmove(env, ((env->dx > isr->is_shiftx) ? SHIFT_INC : -SHIFT_INC));
		isr->is_shiftx = env->dx;
	}
	if (isr->is_shifty != env->dy && (isr->is_render = true))
	{
		fdf_ymove(env, ((env->dy > isr->is_shifty) ? SHIFT_INC : -SHIFT_INC));
		isr->is_shifty = env->dy;
	}
}

void		fdf_rendering(t_env *env)
{
	static t_isrender	isr;

	env->frog ? (isr.is_frog = true) : false;
	if (!env->render)
		if (!fdf_init_render_buff(env))
		{
			fdf_free_env(&env);
			exit(EXIT_SUCCESS);
		}
	if (!isr.is_isr_init)
		add_is_render_init(&isr, env);
	add_is_render(&isr, env);
	add_is_render_rot(&isr, env);
	fdf_is_render_frog(&isr, env);
	if (isr.is_render)
	{
		fdf_refresh_image(env);
		if (env->is_frog_render)
			fdf_print_fucking_frog(env);
	}
}
