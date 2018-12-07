/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_moving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/07 14:56:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_xmove(t_env *env, int inc)
{
	int	y;
	int	x;

	y = NEG;
	inc < 0 ? (env->shift_x -= _ABS(inc)) : (env->shift_x += inc);
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
			inc < 0 ? (env->m[y][x].x -= _ABS(inc)) : (env->m[y][x].x += inc);
	fdf_rendering(env);
}

void	fdf_ymove(t_env *env, int inc)
{
	int	y;
	int	x;

	y = NEG;
	inc < 0 ? (env->shift_y -= _ABS(inc)) : (env->shift_y += inc);
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
			inc < 0 ? (env->m[y][x].y -= _ABS(inc)) : (env->m[y][x].y += inc);
	fdf_rendering(env);
}

void	fdf_xrotare(t_env *env, int inc)
{
	int	oy;
	int	oz;
	int	y;
	int	x;

	y = NEG;
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
		{
			oy = env->buff[y][x].y;
			oz = env->buff[y][x].z;
			env->buff[y][x].y = oy * cos(_RAD(inc)) + oz * sin(_RAD(inc));
			env->buff[y][x].z = -oy * sin(_RAD(inc)) + oz * sin(_RAD(inc));
		}
}