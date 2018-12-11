/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/11 19:50:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	add_zooming(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			env->buff[y][x].x = env->m[y][x].x * env->zoom;
			env->buff[y][x].y = env->m[y][x].y * env->zoom;
		}
}

void	add_centralize(t_env *env)
{
	int	cy;
	int	cx;
	int	y;
	int	x;

	y = NEG;
	cy = (WIN_Y / 2) - ((env->my * env->zoom) / 2);
	cx = (WIN_X / 2) - ((env->mx * env->zoom) / 2);
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			env->m[y][x].y = env->m[y][x].y + cy;
			env->m[y][x].x = env->m[y][x].x + cx;
		}
}

static bool	add_init_buff(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	_NOTIS_F(env->buff = (matrix)malloc(sizeof(t_matrix*) * env->my));
	while (++y < env->my && (x = NEG))
	{
		_NOTIS_F(env->buff[y] = (t_matrix*)malloc(sizeof(t_matrix)
													* env->mx));
		while (++x < env->mx)
		{
			env->buff[y][x].rgb = env->m[y][x].rgb;
			env->buff[y][x].y = env->m[y][x].y;
			env->buff[y][x].x = env->m[y][x].x;
			env->buff[y][x].z = env->m[y][x].z;
		}
	}
	return (true);
}

void	add_print(t_env *env, bool mode)
{
	int	y;
	int	x;

	y = NEG;
	if (mode)
		while (++y < env->my && (x = NEG))
		{
			while (++x < env->mx)
			{
				printf("m: %d | %d\n", env->m[y][x].y, env->m[y][x].x);
				printf("b: %d | %d\n", env->buff[y][x].y, env->buff[y][x].x);
			}
			printf("\n");
		}
	else
		printf("%d | %d\n", env->my, env->mx);
}

void	add_isometric(t_env *env)
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
			env->buff[y][x].y = (1 / sqrt(6)) * (-ox + 2 * oy + oz);
			env->buff[y][x].x = (1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz);
			env->buff[y][x].z = (1 / sqrt(6)) *
						(sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz);
		}
}

static void	add_change_grid_color(t_env *env, int old, int new)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
			if (env->buff[y][x].rgb == old)
				env->buff[y][x].rgb = new;
}

bool		fdf_rendering(t_env *env)
{
	static bool	is_isometric;
	static bool	is_center;
	static int	is_color;

	if (!env->buff)
		add_init_buff(env);
	if (!is_isometric ? (is_isometric = true) : false)
		add_isometric(env);
	if (!is_center ? (is_center = true) : false)
		;// add_centralize(env);
	// add_zooming(env);
	// add_print(env, false);
	if (!is_color)
		is_color = env->color;
	else if (is_color != env->color)
	{
		add_change_grid_color(env, is_color, env->color);
		is_color = env->color;
	}
	mlx_clear_window(env->mlx, env->win);
	fdf_bdrawing(env);
	return (true);
}
