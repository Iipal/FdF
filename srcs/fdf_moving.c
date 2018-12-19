/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_moving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/19 13:53:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_xmove(t_env *env, int inc)
{
	int	y;
	int	x;

	y = NEG;
	inc < 0 ? (env->sx -= _ABS(inc)) : (env->sx += inc);
	_WHILE(y, x, env->my, env->mx)
		inc < 0 ? (env->raw[y][x].x -= _ABS(inc)) : (env->raw[y][x].x += inc);
}

void	fdf_ymove(t_env *env, int inc)
{
	int	y;
	int	x;

	y = NEG;
	inc < 0 ? (env->sy -= _ABS(inc)) : (env->sy += inc);
	_WHILE(y, x, env->my, env->mx)
		inc < 0 ? (env->raw[y][x].y -= _ABS(inc)) : (env->raw[y][x].y += inc);
}

void	fdf_xrotare(t_env *env, int inc)
{
	int	oy;
	int	y;
	int	x;

	y = NEG;
	_WHILE(y, x, env->my, env->mx)
	{
		oy = env->raw[y][x].y;
		env->raw[y][x].y = oy * cos(_RAD(inc)) +
						env->raw[y][x].z * sin(_RAD(inc));
		env->raw[y][x].z = -oy * sin(_RAD(inc)) +
						env->raw[y][x].z * cos(_RAD(inc));
	}
}

void	fdf_yrotare(t_env *env, int inc)
{
	int	ox;
	int	y;
	int	x;

	y = NEG;
	_WHILE(y, x, env->my, env->mx)
	{
		ox = env->raw[y][x].x;
		env->raw[y][x].x = ox * cos(_RAD(inc)) +
						env->raw[y][x].z * sin(_RAD(inc));
		env->raw[y][x].z = -ox * sin(_RAD(inc)) +
						env->raw[y][x].z * cos(_RAD(inc));
	}
}

void	fdf_zrotare(t_env *env, int inc)
{
	int	ox;
	int	y;
	int	x;

	y = NEG;
	_WHILE(y, x, env->my, env->mx)
	{
		ox = env->raw[y][x].x;
		env->raw[y][x].x = ox * cos(_RAD(inc)) -
						env->raw[y][x].y * sin(_RAD(inc));
		env->raw[y][x].y = -ox * sin(_RAD(inc)) +
						env->raw[y][x].y * cos(_RAD(inc));
	}
}
