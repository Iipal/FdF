/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/06 18:19:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*static void	add_print_mnbuff(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->matrix_y && (x = NEG))
	{
		while (++x < env->matrix_x)
		{
			printf("m: %3d - %3d - %4d\t| %d\n",
				env->m[y][x].y, env->m[y][x].x,
				env->m[y][x].z, env->m[y][x].rgb);
			printf("b: %3d - %3d - %4d\t| %d\n",
				env->buff[y][x].y, env->buff[y][x].x,
				env->buff[y][x].z, env->buff[y][x].rgb);
		}
	}
	printf("%d | %d\n", env->matrix_y, env->matrix_x);
}*/

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

bool		fdf_rendering(t_env *env)
{
	if (!env->buff)
		add_init_buff(env);
	add_zooming(env);
	fdf_bdrawing(env->buff, env->matrix_y, env->matrix_x,
		(t_mlx){.mlx = env->mlx, .win = env->win});
	return (true);
}
