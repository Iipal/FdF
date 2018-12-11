/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_moving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/11 09:50:51 by tmaluh           ###   ########.fr       */
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
}

void	fdf_xrotare(t_env *env, int inc)
{
	int	oy;
	int	y;
	int	x;

	y = NEG;
	if (inc)
		;
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
		{
			oy = env->m[y][x].y;
			env->m[y][x].y = oy * cos(_RAD(inc)) +
							env->m[y][x].z * sin(_RAD(inc));
			env->m[y][x].z = -oy * sin(_RAD(inc)) +
							env->m[y][x].z * cos(_RAD(inc));
		}
}

void	fdf_yrotare(t_env *env, int inc)
{
	int	ox;
	int	y;
	int	x;

	y = NEG;
	if (inc)
		;
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
		{
			ox = env->m[y][x].x;
			env->m[y][x].x = ox * cos(_RAD(inc)) +
							env->m[y][x].z * sin(_RAD(inc));
			env->m[y][x].z = -ox * sin(_RAD(inc)) +
							env->m[y][x].z * cos(_RAD(inc));
		}
}

void	fdf_zrotare(t_env *env, int inc)
{
	int	ox;
	int	y;
	int	x;

	y = NEG;
	if (inc)
		;
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
		{
			ox = env->m[y][x].x;
			env->m[y][x].x = ox * cos(_RAD(inc)) -
							env->m[y][x].y * sin(_RAD(inc));
			env->m[y][x].y = -ox * sin(_RAD(inc)) +
							env->m[y][x].y * cos(_RAD(inc));
		}
}
