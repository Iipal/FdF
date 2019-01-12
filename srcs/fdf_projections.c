/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/12 12:46:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_isometric_center(t_env *env)
{
	point		p;
	fpoint		min;
	fpoint		max;
	fpoint		center;

	p.y = ZERO;
	min = (fpoint) {env->render[ZERO][ZERO].y, env->render[ZERO][ZERO].x};
	max = (fpoint) {env->render[env->my - 1][env->mx - 1].y,
					env->render[env->my - 1][env->mx - 1].x};
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			(max.x < _X * env->zoom) ? (max.x = _X * env->zoom) : ZERO;
			(min.x > _X * env->zoom) ? (min.x = _X * env->zoom) : ZERO;
			(min.y > _Y * env->zoom) ? (min.y = _Y * env->zoom) : ZERO;
			(max.y < _Y * env->zoom) ? (max.y = _Y * env->zoom) : ZERO;
		}
	center.x = (max.x - min.x) / 2.0;
	center.y = (max.y - min.y) / 2.0;
	env->sx = -((WIN_X - center.x) / 2);
	env->sy = -((WIN_Y - center.y) / 2);
	ft_putnbr(env->sx);
	write(1, " ", 1);
	ft_putnbr(env->sy);
	write(1, "\n", 1);
}

void		fdf_isometric(t_env *env)
{
	point	p;
	int		oy;
	int		ox;
	int		oz;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			oy = _Y;
			ox = _X;
			oz = _Z;
			env->render[p.y][p.x] = (t_matrix) {
			(1 / sqrt(6)) * (-ox + 2 * oy + oz),
			(1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz),
			(1 / sqrt(6)) * (sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz),
												env->render[p.y][p.x].rgb };
		}
	add_isometric_center(env);
}
