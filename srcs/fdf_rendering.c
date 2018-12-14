/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/14 17:18:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		add_zooming(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			env->buff[y][x].x *= env->zoom;
			env->buff[y][x].y *= env->zoom;
		}
}

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
			env->buff[y][x].rgb = env->m[y][x].rgb;
			env->buff[y][x].y = env->m[y][x].y;
			env->buff[y][x].x = env->m[y][x].x;
			env->buff[y][x].z = env->m[y][x].z;
		}
	}
	return (true);
}

void		add_isometric(t_env *env)
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
			oy = env->buff[y][x].y;
			ox = env->buff[y][x].x;
			oz = env->buff[y][x].z;
			env->buff[y][x].y = (1 / sqrt(6)) * (-ox + 2 * oy + oz);
			env->buff[y][x].x = (1 / sqrt(6)) * (sqrt(3) * ox + sqrt(3) * oz);
			env->buff[y][x].z = (1 / sqrt(6)) *
						(sqrt(2) * ox - sqrt(2) * oy + sqrt(2) * oz);
		}
	// fdf_yrotare(env, 120);
}

void		add_centralize(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	env->sy = (WIN_Y / 2) - ((env->my / 2) * env->zoom);
	env->sx = (WIN_X / 2) - ((env->mx / 2) * env->zoom);
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			env->buff[y][x].y += env->sy;
			env->buff[y][x].x += env->sx;
		}
}

void		add_change_grid_color(t_env *env, int old, int new)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
			if (env->buff[y][x].rgb == old)
				env->buff[y][x].rgb = new;
}

static void	add_is_render_bonus(t_isrender *isr, t_env *env)
{
	if (!isr->is_color && (isr->is_render = true))
		isr->is_color = env->color;
	else if (isr->is_color != env->color && (isr->is_render = true))
	{
		add_change_grid_color(env, isr->is_color, env->color);
		isr->is_color = env->color;
	}
}

static void	add_is_render(t_isrender *isr, t_env *env)
{
	isr->is_render = false;
	if (!isr->is_zoomed && (isr->is_render = true))
	{
		add_zooming(env);
		isr->is_zoomed = true;
	}
	if (!isr->is_isometric ? (isr->is_isometric = true) : false)
		add_isometric(env);
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
	add_is_render(&isr, env);
	add_is_render_bonus(&isr, env);
	if (isr.is_render)
	{
		mlx_clear_window(env->mlx, env->win);
		fdf_bdrawing(env->buff, (t_p){.y = env->my, .x = env->mx},
					(t_mlx){.mlx = env->mlx, .win = env->win});
	}
}
