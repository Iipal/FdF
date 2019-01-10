/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 19:13:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static void	add_init_centralize(t_env *env)
{
	point	p;

	p.y = NEG;
	env->sy = (WIN_Y - ((env->my - 1.0) * env->zoom)) / 2;
	env->sx = (WIN_X - ((env->mx - 1.0) * env->zoom)) / 2;
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
	*isr = (t_isrender){isr->is_color, env->zoom, ZERO, env->dy, env->dx, true, true,
						isr->is_center, isr->is_frog};
	fdf_zooming(env);
	add_init_centralize(env);
}

static void	add_is_render(t_isrender *isr, t_env *env)
{
	isr->is_render = false;
	if (!isr->is_init)
		add_is_render_init(isr, env);
	if (isr->is_zoomed != env->zoom && (isr->is_render = true))
		fdf_refresh_buff(env, isr);
	if (isr->is_project != env->project && (isr->is_render = true))
	{
		isr->is_project = env->project;
		env->project == P_ISO ? fdf_refresh_buff(env, isr) : false;
		env->project == P_PAR ? fdf_refresh_buff(env, isr) : false;
	}
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
	add_is_render(&isr, env);
	fdf_is_render_frog(&isr, env);
	if (isr.is_render)
	{
		fdf_refresh_image(env);
		if (env->is_frog_render)
			fdf_print_fucking_frog(env);
	}
}
