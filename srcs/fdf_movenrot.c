/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movenrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/20 16:04:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_xmove(t_env *env, int inc)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			inc < 0 ? (env->render[p.y][p.x].x -= _ABS(inc))
					: (env->render[p.y][p.x].x += inc);
}

void	fdf_ymove(t_env *env, int inc)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			inc < 0 ? (env->render[p.y][p.x].y -= _ABS(inc))
					: (env->render[p.y][p.x].y += inc);
}

void	fdf_xrotare(t_env *env, int inc)
{
	int	oy;
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			oy = env->render[y][x].y;
			env->render[y][x].y = oy * cos(_RAD(inc)) +
							env->render[y][x].z * sin(_RAD(inc));
			env->render[y][x].z = -oy * sin(_RAD(inc)) +
							env->render[y][x].z * cos(_RAD(inc));
		}
}

void	fdf_yrotare(t_env *env, int inc)
{
	point	p;
	int		ox;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			ox = env->render[p.y][p.x].x;
			env->render[p.y][p.x].x = ox * cos(_RAD(inc)) +
							env->render[p.y][p.x].z * sin(_RAD(inc));
			env->render[p.y][p.x].z = -ox * sin(_RAD(inc)) +
							env->render[p.y][p.x].z * cos(_RAD(inc));
		}
}

void	fdf_zrotare(t_env *env, int inc)
{
	point	p;
	int		ox;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
		{
			ox = env->render[p.y][p.x].x;
			env->render[p.y][p.x].x = ox * cos(_RAD(inc)) -
							env->render[p.y][p.x].y * sin(_RAD(inc));
			env->render[p.y][p.x].y = -ox * sin(_RAD(inc)) +
							env->render[p.y][p.x].y * cos(_RAD(inc));
		}
}
