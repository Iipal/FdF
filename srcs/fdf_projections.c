/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/17 19:26:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_isometric(t_env *env)
{
	int	oy;
	int	ox;
	int	oz;
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			oy = env->m[y][x].y;
			ox = env->m[y][x].x;
			oz = env->m[y][x].z;
			env->m[y][x].y = (1 / sqrt(6)) * (-ox + 2 * oy + oz);
			env->m[y][x].x = (1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz);
			env->m[y][x].z = (1 / sqrt(6)) *
						(sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz);
		}
}
