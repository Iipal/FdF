/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/19 13:53:44 by tmaluh           ###   ########.fr       */
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
	_WHILE(y, x, env->my, env->mx)
	{
		oy = env->raw[y][x].y;
		ox = env->raw[y][x].x;
		oz = env->raw[y][x].z;
		env->raw[y][x] = (t_matrix){(1 / sqrt(6)) * (-ox + 2 * oy + oz),
						(1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz),
		(1 / sqrt(6)) * (sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz),
												env->raw[y][x].rgb};
	}
}
