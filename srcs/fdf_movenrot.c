/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movenrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/16 11:43:55 by tmaluh           ###   ########.fr       */
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

/*
*	x' = x;
*	y' := y * cos(L)+ z * sin(L);
*	z' := -y * sin(L)+ z * cos(L);
*
*	x' = x * cos(L) + z * sin(L);
*	y' = y;
*	z' = -x * sin(L) + z * cos(L);
*
*	x' = x * cos(L) - y * sin(L);
*	y' = -x * sin(L) + y * cos(L);
*	z' = z;
**/

void	fdf_rotare_buff(t_env *env)
{
	t_matrix	m;
	point		p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			m = (t_matrix){_Y, _X, _Z, ZERO};
			_Y = m.y * _COSR(env->rotx) + m.z * _SINR(env->rotx);
			_Z = -m.y * _SINR(env->rotx) + m.z * _COSR(env->rotx);
			m = (t_matrix){_Y, _X, _Z, ZERO};
			_X = m.x * _COSR(env->roty) + m.z * _SINR(env->roty);
			_Z = -m.x * _SINR(env->roty) + m.z * _COSR(env->roty);
			m = (t_matrix){_Y, _X, _Z, ZERO};
			_X = m.x * _COSR(env->rotz) - m.y * _SINR(env->rotz);
			_Y = -m.x * _SINR(env->rotz) + m.y * _COSR(env->rotz);
		}
}
