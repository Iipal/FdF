/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movenrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/14 18:03:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_xmove(t_env *env, float inc)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			inc < ZERO ? (_X -= _ABS(inc)) : (_X += inc);
}

void		fdf_ymove(t_env *env, float inc)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			inc < ZERO ? (_Y -= _ABS(inc)) : (_Y += inc);
}

static void	add_xyzrot_formula(t_env *env, t_matrix *m, point *p, point *c)
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

void		fdf_rotare(t_env *env)
{
	point		p;
	point		c;
	t_matrix	m;

	c = (point){(env->sy - ((env->my - 1.0) * env->zoom)) / 2,
				(env->sx - ((env->mx - 1.0) * env->zoom)) / 2};
	m.rgb = env->render[env->my / 2][env->mx / 2].z;
	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			add_xyzrot_formula(env, &m, &p, &c);
}
