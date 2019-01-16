/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:45:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/16 20:04:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	fdf_init_render_buff(t_env *env)
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
				env->render[p.y][p.x] = (t_matrix) { env->raw[p.y][p.x].y,
								env->raw[p.y][p.x].x, env->raw[p.y][p.x].z,
								env->raw[p.y][p.x].rgb};
	return (true);
}

void	fdf_center_of_buff(t_env *env)
{
	point		p;
	t_3d_p		min;
	t_3d_p		max;

	p.y = ZERO;
	min = (t_3d_p){(**(env->render)).y,
		(**(env->render)).x, (**(env->render)).z};
	max = (t_3d_p){(**(env->render)).y,
		(**(env->render)).x, (**(env->render)).z};
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
		(max.x + min.x) / 2, (max.z + min.z) / 2};
	env->sy = (WIN_Y / 2) - env->fcenter.y + env->dy;
	env->sx = (WIN_X / 2) - env->fcenter.x + env->dx;
}


void	fdf_zooming_buff(t_env *env)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			env->render[p.y][p.x] = (t_matrix){
				env->raw[p.y][p.x].y * env->zoom,
				env->raw[p.y][p.x].x * env->zoom,
				env->raw[p.y][p.x].z * env->zoom,
				env->render[p.y][p.x].rgb};
}

void	add_print_matrix(t_env *env)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
	{
		while (++(p.x) < env->mx)
			printf("%lf - %lf - %lf | ", _Y, _X, _Z);
		printf("\n");
	}
}

void	fdf_refresh_buff(t_env *env, t_isrender *isr)
{
	fdf_zooming_buff(env);
	fdf_rotare_buff(env);
	env->project == P_ISO ? fdf_isometric(env) : false;
	isr->is_center ? fdf_center_of_buff(env) : false;
	fdf_move_buff(env, env->sx, env->sy);
	*isr = (t_isrender) {isr->is_color, env->roty, env->rotx,
		env->zoom, env->project, env->dy, env->dx, true, false,
		isr->is_frog, true};
}
