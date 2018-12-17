/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:44:34 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/17 22:14:14 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static void	add_change_grid_color(t_env *env, int old, int new)
{
	int	y;
	int	x;

	y = NEG;
	while (++y < env->my && (x = NEG))
		while (++x < env->mx)
			if (env->m[y][x].rgb == old)
				env->m[y][x].rgb = new;
	y = NEG;
	while (++y < FHEIGHT && (x = NEG))
		while (++x < FWIDTH)
			if (env->frog[y][x] == old)
				env->frog[y][x] = new;
}

void		add_print_fucking_frog(t_env *env)
{
	int	y;
	int	x;

	y = NEG;
	x = NEG;
	while (++y < FHEIGHT && (x = NEG))
		while (++x < FWIDTH)
			mlx_pixel_put(env->mlx, env->win, x, y, env->frog[y][x]);
}

void		add_is_render_bonus(t_isrender *isr, t_env *env)
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

int			**bonus_init_frog(void)
{
	string	gnl_temp;
	int		**out_frog;
	int		fd;
	int		y;

	y = NEG;
	gnl_temp = NULL;
	fd = open(FFILE_NAME, O_RDONLY);
	_NOTIS_N(!(!fd || fd < 0));
	_NOTIS_N(out_frog = (int**)malloc(sizeof(int*) * FHEIGHT));
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
