/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 19:09:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			oy = env->render[p.y][p.x].y;
			ox = env->render[p.y][p.x].x;
			oz = env->render[p.y][p.x].z;
			env->render[p.y][p.x] = (t_matrix) {
			(1 / sqrt(6)) * (-ox + 2 * oy + oz),
			(1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz),
			(1 / sqrt(6)) * (sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz),
												env->render[p.y][p.x].rgb };
		}
}

void		fdf_project(t_env *env)
{
	point	p;
	int		oy;
	int		ox;
	int		oz;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			oy = env->render[p.y][p.x].y;
			ox = env->render[p.y][p.x].x;
			oz = env->render[p.y][p.x].z;
			!oz ? (++oz) : oz;
			env->render[p.y][p.x] = (t_matrix) {
				oz < 0 ? oy / -oz : oy / oz, oz < 0 ? ox / -oz : ox / oz,
				oz, env->render[p.y][p.x].rgb };
		}
}
