/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:45:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/20 12:55:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool		fdf_init_render_buff(t_env *env)
{
	point	p;

	p.y = NEG;
	_NOTIS_F(env->buff = (t_matrix**)malloc(sizeof(t_matrix*) * env->my));
	while (++(p.y) < env->my && (p.x = NEG))
		if (!(env->buff[p.y] = (t_matrix*)malloc(sizeof(t_matrix) * env->mx)))
		{
			fdf_free_matrix(&(env->buff), p.y);
			fdf_free_env(&env);
			return (false);
		}
		else
			while (++(p.x) < env->mx)
				env->buff[p.y][p.x] = (t_matrix) { env->raw[p.y][p.x].y,
					env->raw[p.y][p.x].x, env->raw[p.y][p.x].z,
					env->raw[p.y][p.x].rgb};
	return (true);
}

void		fdf_center_of_buff(t_env *env)
{
	point		p;
	t_3d_p		min;
	t_3d_p		max;

	p.y = ZERO;
	min = (t_3d_p){(**(env->buff)).y,
		(**(env->buff)).x, (**(env->buff)).z};
	max = (t_3d_p){(**(env->buff)).y,
		(**(env->buff)).x, (**(env->buff)).z};
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			(max.x < _X) ? (max.x = _X) : ZERO;
			(min.x > _X) ? (min.x = _X) : ZERO;
			(max.y < _Y) ? (max.y = _Y) : ZERO;
			(min.y > _Y) ? (min.y = _Y) : ZERO;
			(max.z < _Z) ? (max.z = _Z) : ZERO;
			(min.z > _Z) ? (min.z = _Z) : ZERO;
		}
	env->fcenter = (t_3d_p) {(max.y + min.y) / 2,
		(max.x - min.x) / 2, (max.z - min.z) / 2};
	env->sy = (WIN_Y / 2) - env->fcenter.y + env->dy;
	env->sx = (WIN_X / 2) - env->fcenter.x + env->dx;
}

void		fdf_zooming_buff(t_env *env)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			env->buff[p.y][p.x] = (t_matrix){
			env->raw[p.y][p.x].y * env->zoom, env->raw[p.y][p.x].x * env->zoom,
			env->raw[p.y][p.x].z * env->zoom, env->raw[p.y][p.x].rgb};
}

void		fdf_refresh_buff(t_env *env)
{
	fpoint	temp_shifts;

	fdf_zooming_buff(env);
	temp_shifts = (fpoint){env->sy, env->sx};
	if (env->project == P_ISO)
	{
		fdf_center_of_buff(env);
		fdf_rotare_buff(env);
		fdf_isometric(env);
		fdf_center_of_buff(env);
		(env->rotx != env->isr.is_rotx) ? (env->sx = temp_shifts.x) : false;
		(env->roty != env->isr.is_roty) ? (env->sy = temp_shifts.y) : false;
	}
	else
	{
		fdf_center_of_buff(env);
		fdf_rotare_buff(env);
	}
	fdf_move_buff(env, env->sx, env->sy);
	env->isr = (t_isrender) {env->color, env->roty, env->rotx, env->zoom,
		env->project, env->dy, env->dx, false, env->isr.is_frog};
}
