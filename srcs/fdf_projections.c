/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/17 17:47:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_isometric(t_env *env)
{
	point	p;
	t_3d_p	o;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			o = (t_3d_p) {_Y, _X, _Z};
			env->buff[p.y][p.x] = (t_matrix) {
				(1 / sqrt(6)) * (-o.x + 2 * o.y + o.z),
				(1 / sqrt(6)) * (sqrt(3) * o.x + sqrt(3) * o.z),
				(1 / sqrt(6)) * (sqrt(2) * o.x - sqrt(2) * o.y + sqrt(2) * o.z),
				env->buff[p.y][p.x].rgb };
		}
}
