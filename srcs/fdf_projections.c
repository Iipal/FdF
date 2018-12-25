/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/25 13:45:21 by ipal             ###   ########.fr       */
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

void		fdf_perspective(t_env *env)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			env->render[p.y][p.x] = (t_matrix) {
				(env->zoom * env->render[p.y][p.x].y)
						/ (env->render[p.y][p.x].z + env->zoom),
				(env->zoom * env->render[p.y][p.x].x)
						/ (env->render[p.y][p.x].z + env->zoom),
				env->render[p.y][p.x].z,
				env->render[p.y][p.x].rgb };
}
