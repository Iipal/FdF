/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_frog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:44:34 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/20 09:49:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

void		fdf_print_fucking_frog(t_env *env)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < FHEIGHT && (p.x = NEG))
		while (++(p.x) < FWIDTH)
			if (env->frog[p.y][p.x] != FBG_COLOR)
				mlx_pixel_put(env->mlx, env->win,
						p.x, p.y, env->frog[p.y][p.x]);
}

static void	add_change_grid_color(t_env *env, int old, int new)
{
	point	p;

	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			if (env->render[p.y][p.x].rgb == old)
				env->render[p.y][p.x].rgb = new;
	p.y = NEG;
	while (++(p.y) < FHEIGHT && (p.x = NEG))
		while (++(p.x) < FWIDTH)
			if (env->frog[p.y][p.x] == old)
				env->frog[p.y][p.x] = new;
}

void		fdf_is_render_frog(t_isrender *isr, t_env *env)
{
	if (isr->is_frog && env->is_frog_render)
	{
		if (!isr->is_color && (isr->is_render = true))
			isr->is_color = env->color;
		else if (isr->is_color != env->color && (isr->is_render = true))
		{
			add_change_grid_color(env, isr->is_color, env->color);
			isr->is_color = env->color;
		}
	}
}

static bool	add_save_to_frog(int *frog, string line)
{
	int	x;

	x = ZERO;
	while (*line && x < FWIDTH)
	{
		if (ft_isdigit(*line))
		{
			frog[x] = IRGB_WHITE;
			if (*(++line) == ',')
				_NOTIS_F(frog[x] = ft_atoi_base(line + 3, HEX));
			while (*line && !ft_isblank(*line))
				++line;
			++x;
		}
		*line ? ++line : 0;
	}
	return (true);
}

itab		fdf_bonus_init_frog(void)
{
	string	gnl_temp;
	itab	out_frog;
	int		fd;
	int		y;

	y = NEG;
	gnl_temp = NULL;
	_NOTIS_N(!(!(fd = open(FFILE_NAME, O_RDONLY)) || fd < 0));
	_NOTIS_N(out_frog = (itab)malloc(sizeof(int*) * FHEIGHT));
	while (++y < FHEIGHT)
		_NOTIS_N(out_frog[y] = (int*)malloc(sizeof(int) * FWIDTH));
	y = NEG;
	while (ft_gnl(fd, &gnl_temp) > ZERO)
	{
		_NOTIS_N(add_save_to_frog(out_frog[++y], gnl_temp));
		ft_strdel(&gnl_temp);
	}
	close(fd);
	return (out_frog);
}
