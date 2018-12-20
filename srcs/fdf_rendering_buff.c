/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:45:57 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/20 21:04:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	fdf_init_render_buff(t_env *env)
{
	point	p;

	p.y = NEG;
	_NOTIS_F(env->render = (t_matrix**)malloc(sizeof(t_matrix*) * env->my));
	while (++(p.y) < env->my && (p.x = NEG))
		if (!(env->render[p.y] = (t_matrix*)malloc(sizeof(t_matrix) * env->mx)))
		{
			fdf_free_matrix(env->render, p.y);
			return (false);
		}
		else
			while (++(p.x) < env->mx)
				env->render[p.y][p.x] = (t_matrix)
				{
					env->raw[p.y][p.x].y,
					env->raw[p.y][p.x].x,
					env->raw[p.y][p.x].z,
					env->raw[p.y][p.x].rgb
				};
	return (true);
}

void	fdf_refresh_buffnzoom(t_env *env, t_isrender *isr)
{
	env->sy = ((WIN_Y - ((float)env->my * env->zoom)) / 2);
	env->sx = ((WIN_X - ((float)env->mx * env->zoom)) / 2);
	env->dx < ZERO ? (env->sx += (_ABS(env->dx) * env->zoom))
					: (env->sx += (env->dx * env->zoom));
	env->dy < ZERO ? (env->sy -= (_ABS(env->dy) * env->zoom))
					: (env->sy -= (env->dy * env->zoom));
	fdf_zooming(env);
	fdf_isometric(env);
	fdf_ymove(env, env->sy);
	fdf_xmove(env, env->sx);
	isr->is_shifty = env->sy;
	isr->is_shiftx = env->sx;
}
