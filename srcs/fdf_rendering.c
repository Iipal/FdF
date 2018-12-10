/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/10 16:08:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	add_zooming(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
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
	cy = (WIN_Y / 2) - ((env->matrix_y * env->zoom) / 2);
	cx = (WIN_X / 2) - ((env->matrix_x * env->zoom) / 2);
	// mlx_pixel_put(env->mlx, env->win, cx, cy, 4063076);
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
		{
			env->buff[y][x].y = env->m[y][x].y + cy;
			env->buff[y][x].x = env->m[y][x].x + cx;
		}
}

static bool	add_init_buff(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	_NOTIS_F(env->buff = (matrix)malloc(sizeof(t_matrix*) * env->matrix_y));
	while (++y < env->matrix_y && (x = NEG))
	{
		_NOTIS_F(env->buff[y] = (t_matrix*)malloc(sizeof(t_matrix)
													* env->matrix_x));
		while (++x < env->matrix_x)
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
		while (++y < env->matrix_y && (x = NEG))
		{
			while (++x < env->matrix_x)
			{
				printf("m: %d | %d\n", env->m[y][x].y, env->m[y][x].x);
				printf("b: %d | %d\n", env->buff[y][x].y, env->buff[y][x].x);
			}
			printf("\n");
		}
	else
		printf("%d | %d\n", env->matrix_y, env->matrix_x);
}

void	add_isometric(t_env *env)
{
	int	oy;
	int	ox;
	int	oz;
	int	y;
	int	x;

	y = NEG;
	while (++y < env->matrix_y && (x = NEG))
		while (++x < env->matrix_x)
		{
			oy = env->m[y][x].y;
			ox = env->m[y][x].x;
			oz = env->m[y][x].z;
			env->buff[y][x].y = (1 / sqrt(6)) * (-ox + 2 * oy + oz) * env->zoom;
			env->buff[y][x].x = (1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz) * env->zoom;
			env->buff[y][x].z = (1 / sqrt(6)) *
						(sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz) * env->zoom;
		}
}

bool		fdf_rendering(t_env *env)
{
	static bool	is_center;
	
	if (!env->buff)
		add_init_buff(env);
	if (!is_center ? (is_center = true) : false)
		;// add_centralize(env);
	add_zooming(env);
	add_isometric(env);
	add_print(env, false);
	mlx_clear_window(env->mlx, env->win);
	fdf_bdrawing(env->buff, env->matrix_y, env->matrix_x,
		(t_mlx){.mlx = env->mlx, .win = env->win});
	return (true);
}
