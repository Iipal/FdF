/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/12 17:29:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		add_zooming(t_env *env, int old_zoom, int new_zoom)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			env->buff[y][x].x = env->m[y][x].x / old_zoom * new_zoom;
			env->buff[y][x].y = env->m[y][x].y / old_zoom * new_zoom;
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
}

void		add_centralize(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	env->cy = (WIN_Y / 2) - ((env->my / 2) * env->zoom);
	env->cx = (WIN_X / 2) - ((env->mx / 2) * env->zoom);
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
		{
			env->buff[y][x].y += env->cy;
			env->buff[y][x].x += env->cx;
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
	if (!isr->is_color)
		isr->is_color = env->color;
	else if (isr->is_color != env->color)
	{
		add_change_grid_color(env, isr->is_color, env->color);
		isr->is_color = env->color;
	}
}

static void	add_is_render(t_isrender *isr, t_env *env)
{
	if (!isr->is_zoomed)
	{
		isr->is_zoomed = env->zoom;
		add_zooming(env, 1, isr->is_zoomed);
	}
	else if (isr->is_zoomed != env->zoom)
	{
		add_zooming(env, isr->is_zoomed, env->zoom);
		isr->is_zoomed = env->zoom;
	}
	if (!isr->is_center ? (isr->is_center = true) : false)
		add_centralize(env);
	if (!isr->is_shiftx)
		isr->is_shiftx = env->cx;
	else if (isr->is_shiftx != env->cx)
	{
		fdf_xmove(env, ((env->cx > isr->is_shiftx) ? SHIFT_INC : -SHIFT_INC));
		isr->is_shiftx = env->cx;
	}
	if (!isr->is_shifty)
		isr->is_shifty = env->cy;
	else if (isr->is_shifty != env->cy)
	{
		fdf_ymove(env, ((env->cy > isr->is_shifty) ? SHIFT_INC : -SHIFT_INC));
		isr->is_shifty = env->cy;
	}
}

bool		fdf_rendering(t_env *env)
{
	static t_isrender	isr;

	if (!env->buff)
		add_init_buff(env);
	add_is_render(&isr, env);
	add_is_render_bonus(&isr, env);
	mlx_clear_window(env->mlx, env->win);
	fdf_bdrawing(env);
	return (true);
}
