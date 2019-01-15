/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movenrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/15 20:35:42 by tmaluh           ###   ########.fr       */
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

/* static void	add_xyzrot_formula(t_env *env, t_matrix *m, point *p, fpoint *c)
{
	*m = (t_matrix){_YP, _XP, _ZP, m->rgb};
	_YP = c->y + (m->y - c->y) * _COS(env->rotx)
		+ (m->rgb - m->z) * _SIN(env->rotx);
	_ZP = m->rgb + (m->y - c->y) * _SIN(env->rotx)
		+ (m->z - m->rgb) * _COS(env->rotx);
	*m = (t_matrix){_YP, _XP, _ZP, m->rgb};
	_XP = c->x + (m->x - c->x) * _COS(env->roty)
		+ (m->z - m->rgb) * _SIN(env->roty);
	_ZP = m->rgb + (c->x - m->x) * _SIN(env->roty)
		+ (m->z - m->rgb) * _COS(env->roty);
	*m = (t_matrix){_YP, _XP, _ZP, m->rgb};
	_XP = c->x + (m->x - c->x) * _COS(env->rotz)
		+ (c->y - m->y) * _SIN(env->rotz);
	_YP = c->y + (m->x - c->x) * _SIN(env->rotz)
		+ (m->y - c->y) * _COS(env->rotz);
}

void		fdf_rotare_buff(t_env *env)
{
	point		p;
	fpoint		c;
	t_matrix	m;

	c = (fpoint){env->sy - (((env->my - 1.0) * env->zoom) / 2),
				env->sx - (((env->mx - 1.0) * env->zoom) / 2)};
	m.rgb = env->render[env->my / 2][env->mx / 2].z;
	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			add_xyzrot_formula(env, &m, &p, &c);
}*/

/* x'=x;
y':=y*cos(L)+z*sin(L) ;
z':=-y*sin(L)+z*cos(L) ;

x'=x*cos(L)+z*sin(L);
y'=y;
z'=-x*sin(L)+z*cos(L);

x'=x*cos(L)-y*sin(L);
y'=-x*sin(L)+y*cos(L);
z'=z; */

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
