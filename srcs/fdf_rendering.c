/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/20 10:01:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static void	add_centralize(t_env *env)
{
	point	p;

	p.y = NEG;
	env->sy = (WIN_Y / 2) - ((env->my / 2) * env->zoom);
	env->sx = (WIN_X / 2) - ((env->mx / 2) * env->zoom);
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			env->render[p.y][p.x].y += env->sy;
			env->render[p.y][p.x].x += env->sx;
		}
}

static void	add_zooming(t_env *env)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			env->render[p.y][p.x].y *= env->zoom;
			env->render[p.y][p.x].x *= env->zoom;
			env->render[p.y][p.x].z *= env->zoom;
		}
}

static void	add_is_render(t_isrender *isr, t_env *env)
{
	isr->is_render = false;
	if ((!isr->is_zoomed) ? (isr->is_zoomed = true) : false)
		add_zooming(env);
	if (!isr->is_isometric ? (isr->is_isometric = true) : false)
		fdf_isometric(env);
	if ((!isr->is_center ? (isr->is_center = true) : 0)
			&& (isr->is_render = true))
		add_centralize(env);
	!isr->is_shiftx ? (isr->is_shiftx = env->sx) : 0;
	if (isr->is_shiftx != env->sx && (isr->is_render = true))
	{
		fdf_xmove(env, ((env->sx > isr->is_shiftx) ? SHIFT_INC : -SHIFT_INC));
		isr->is_shiftx = env->sx;
	}
	!isr->is_shifty ? (isr->is_shifty = env->sy) : 0;
	if (isr->is_shifty != env->sy && (isr->is_render = true))
	{
		fdf_ymove(env, ((env->sy > isr->is_shifty) ? SHIFT_INC : -SHIFT_INC));
		isr->is_shifty = env->sy;
	}
}

void		fdf_rendering(t_env *env)
{
	static t_isrender	isr;

	if (env->frog)
		isr.is_frog = true;
	if (!env->render)
		if (!fdf_init_render_buff(env))
		{
			fdf_free_env(env);
			exit(EXIT_SUCCESS);
		}
	add_is_render(&isr, env);
	fdf_is_render_frog(&isr, env);
	if (isr.is_render)
	{
		mlx_clear_window(env->mlx, env->win);
		fdf_bdrawing(env->render, (t_p){.y = env->my, .x = env->mx},
					(t_mlx){.mlx = env->mlx, .win = env->win});
		if (env->is_frog_render)
			fdf_print_fucking_frog(env);
	}
}
