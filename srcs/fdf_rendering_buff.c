/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:45:57 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/25 14:11:31 by ipal             ###   ########.fr       */
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
	float	shift_y;
	float	shift_x;
	
	shift_y = ((WIN_Y - ((env->my - 1.0) * env->zoom)) / 2.0) + env->dy;
	shift_x = ((WIN_X - ((env->mx - 1.0) * env->zoom)) / 2.0) + env->dx;
	fdf_zooming(env);
	if (env->project == P_PER)
	{
		if (isr->is_perspective)
			fdf_perspective(env);
		else
		{
			_MSG(E_IPER);
			env->project = P_RAW;
		}
	}
	env->project == P_ISO ? fdf_isometric(env) : false;
	env->project == P_RAW ? (env->project = P_RAW) : false;
	fdf_ymove(env, shift_y);
	fdf_xmove(env, shift_x);
	isr->is_shifty = env->dy;
	isr->is_shiftx = env->dx;
	isr->is_zoomed = env->zoom;
	isr->is_project = env->project;
}

void		fdf_refresh_buff(t_env *env, t_isrender *isr)
{
	fdf_refresh_zoom(env, isr);
	fdf_xrotare(env, env->rotx);
	fdf_yrotare(env, env->roty);
	fdf_zrotare(env, env->rotz);
	isr->is_roty = env->roty;
	isr->is_rotx = env->rotx;
	isr->is_rotz = env->rotz;
}
