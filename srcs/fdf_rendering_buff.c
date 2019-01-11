/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:45:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/11 11:28:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool		fdf_init_render_buff(t_env *env)
{
	point	p;

	p.y = NEG;
	_NOTIS_F(env->render = (t_matrix**)malloc(sizeof(t_matrix*) * env->my));
	while (++(p.y) < env->my && (p.x = NEG))
		if (!(env->render[p.y] = (t_matrix*)malloc(sizeof(t_matrix) * env->mx)))
		{
			fdf_free_matrix(&(env->render), p.y);
			fdf_free_env(&env);
			return (false);
		}
		else
			while (++(p.x) < env->mx)
				env->render[p.y][p.x] = (t_matrix)
				{
					env->raw[p.y][p.x].y,
					env->raw[p.y][p.x].x,
					env->raw[p.y][p.x].z,
					env->raw[p.y][p.x].rgb
				};
	return (true);
}

void		fdf_zooming(t_env *env)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			env->render[p.y][p.x] = (t_matrix)
			{
				env->raw[p.y][p.x].y * env->zoom,
				env->raw[p.y][p.x].x * env->zoom,
				env->raw[p.y][p.x].z * env->zoom,
				env->render[p.y][p.x].rgb
			};
}

static void	fdf_refresh_zoom(t_env *env, t_isrender *isr)
{
	fdf_zooming(env);
	env->sy = ((WIN_Y - ((env->my - 1.0) * env->zoom)) / 2.0) + env->dy;
	env->sx = ((WIN_X - ((env->mx - 1.0) * env->zoom)) / 2.0) + env->dx;
	env->project == P_ISO ? fdf_isometric(env) : false;
	env->project == P_PAR && (env->project = P_PAR);
	isr->is_shifty = env->dy;
	isr->is_shiftx = env->dx;
	isr->is_zoomed = env->zoom;
	isr->is_project = env->project;
}

void		fdf_refresh_buff(t_env *env, t_isrender *isr)
{
	fdf_refresh_zoom(env, isr);
	fdf_xmove(env, env->sx);
	fdf_ymove(env, env->sy);
}
