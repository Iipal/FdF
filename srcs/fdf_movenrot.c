/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movenrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/29 00:19:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_xmove(t_env *env, float inc)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			inc < ZERO ? (_X -= _ABS(inc)) : (_X += inc);
}

void	fdf_ymove(t_env *env, float inc)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			inc < ZERO ? (_Y -= _ABS(inc)) : (_Y += inc);
}

void	fdf_rotare(t_env *env)
{
	point		p;
	point		half;
	t_matrix	m;

	p.y = NEG;
	half = (point){(env->my / 2) * env->zoom, (env->mx / 2) * env->zoom};
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			m = (t_matrix){_Y, _X, _Z, ZERO};
			_X = half.x + (m.x - half.x) * cos(_RAD(env->rotz))
				+ (half.y - m.y) * sin(_RAD(env->rotz));
			_Y = half.x + (m.x - half.x) * sin(_RAD(env->rotz))
				+ (m.y - half.y) * cos(_RAD(env->rotz));
			_Y = m.y * cos(_RAD(env->rotx)) + m.z * sin(_RAD(env->rotx));
			_Z = -(m.y) * sin(_RAD(env->rotx)) + m.z * sin(_RAD(env->rotx));
			_X = m.x * cos(_RAD(env->roty)) + m.z * sin(_RAD(env->roty));
			_Z = -(m.x) * sin(_RAD(env->roty) + m.z * cos(_RAD(env->roty)));
		}
}
