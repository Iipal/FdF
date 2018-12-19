/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:45:57 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/19 13:44:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	fdf_init_render_buff(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	_NOTIS_F(env->torender = (t_matrix**)malloc(sizeof(t_matrix*) * env->my));
	while (++y < env->my && (x = NEG))
	{
		if (!(env->torender[y] = (t_matrix*)malloc(sizeof(t_matrix) * env->mx)))
		{
			fdf_free_matrix(env->torender, y);
			return (false);
		}
		while (++x < env->mx)
			env->torender[y][x] = (t_matrix){env->raw[y][x].y, env->raw[y][x].x,
										env->raw[y][x].z, env->raw[y][x].rgb};
	}
	return (true);
}
