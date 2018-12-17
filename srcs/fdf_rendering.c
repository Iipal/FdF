/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/17 18:26:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static bool	add_init_buff(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	_NOTIS_F(env->buff = (t_matrix**)malloc(sizeof(t_matrix*) * env->my));
	while (++y < env->my && (x = NEG))
	{
		_NOTIS_F(env->buff[y] = (t_matrix*)malloc(sizeof(t_matrix)
													* env->mx));
		while (++x < env->mx)
		{
			env->buff[y][x].rgb = env->m[y][x].rgb * ZOOM_DEF;
			env->buff[y][x].y = env->m[y][x].y * ZOOM_DEF;
			env->buff[y][x].x = env->m[y][x].x * ZOOM_DEF;
			env->buff[y][x].z = env->m[y][x].z * ZOOM_DEF;
		}
	}
	return (true);
}

void		add_centralize(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	env->sy = (WIN_Y / 2) - ((env->my / 2) * ZOOM_DEF);
	env->sx = (WIN_X / 2) - ((env->mx / 2) * ZOOM_DEF);
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			env->buff[y][x].y += env->sy;
			env->buff[y][x].x += env->sx;
		}
}

static void	add_is_render_sec(t_isrender *isr, t_env *env)
{
	if (isr)
		;
	if (env)
		;
}

static void	add_is_render(t_isrender *isr, t_env *env)
{
	isr->is_render = false;
	if (!isr->is_isometric ? (isr->is_isometric = true) : false)
		fdf_isometric(env);
	if ((!isr->is_center ? (isr->is_center = 1) : 0) && (isr->is_render = true))
		add_centralize(env);
	!isr->is_shiftx ? (isr->is_shiftx = env->sx) : 0;
	if (isr->is_shiftx != env->sx && (isr->is_render = true))
	{
		fdf_xmove(env, ((env->sx > isr->is_shiftx) ? SHIFT_INC : -SHIFT_INC));
		isr->is_shiftx = env->sx;
	}
	!isr->is_shifty ? (isr->is_shifty = env->sy) : 0;
	if (isr->is_shifty != env->sy && (isr->is_render = true))
	{
		fdf_ymove(env, ((env->sy > isr->is_shifty) ? SHIFT_INC : -SHIFT_INC));
		isr->is_shifty = env->sy;
	}
}

void		fdf_rendering(t_env *env)
{
	static t_isrender	isr;

	if (!env->buff)
		add_init_buff(env);
	if (env->frog)
		isr.is_frog = true;
	add_is_render(&isr, env);
	add_is_render_sec(&isr, env);
	add_is_render_bonus(&isr, env);
	if (isr.is_render)
	{
		mlx_clear_window(env->mlx, env->win);
		fdf_bdrawing(env->buff, (t_p){.y = env->my, .x = env->mx},
					(t_mlx){.mlx = env->mlx, .win = env->win});
	}
}
