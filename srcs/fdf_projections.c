/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/17 18:26:15 by tmaluh           ###   ########.fr       */
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
			oy = env->buff[y][x].y;
			ox = env->buff[y][x].x;
			oz = env->buff[y][x].z;
			env->buff[y][x].y = (1 / sqrt(6)) * (-ox + 2 * oy + oz);
			env->buff[y][x].x = (1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz);
			env->buff[y][x].z = (1 / sqrt(6)) *
						(sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz);
		}
}
