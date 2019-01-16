/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movenrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/16 20:30:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_move_buff(t_env *env, float xinc, float yinc)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			xinc < ZERO ? (_X -= _ABS(xinc)) : (_X += xinc);
			yinc < ZERO ? (_Y -= _ABS(yinc)) : (_Y += yinc);
		}
}

void	fdf_rotare_buff(t_env *env)
{
	t_3d_p	m;
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			m = (t_3d_p){_Y, _X, _Z};
			_Y = env->fcenter.y + (m.y - env->fcenter.y) * _COSR(env->rotx) + (env->fcenter.z - m.z) * _SINR(env->rotx);
			_Z = env->fcenter.z + (m.y - env->fcenter.y) * _SINR(env->rotx) + (m.z - env->fcenter.z) * _COSR(env->rotx);
			m = (t_3d_p){_Y, _X, _Z};
			_X = env->fcenter.x + (m.x - env->fcenter.x) * _COSR(env->roty) + (m.z - env->fcenter.z) * _SINR(env->roty);
			_Z = env->fcenter.z + (env->fcenter.x - m.x) * _SINR(env->roty) + (m.z - env->fcenter.z) * _COSR(env->roty);
		}
}
