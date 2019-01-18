/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_additional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:10:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/18 11:22:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

void		fdf_add_print_usage(void)
{
	_MSGN("\t[W | A | S | D] or Arrows for moving.");
	_MSGN("\t[+] & [-] on [numpad | keyboard] for zooming.");
	_MSGN("\t[T | G] - x rotate.  \\");
	_MSGN("\t[C] - bonus.          |---- or use mouse for rotate & zoom");
	_MSGN("\t[Y | H] - y rotate.  /");
	_MSGN("\t[I | P] - projections switch.");
	_MSGN("\t  [I] - Isometric.");
	_MSGN("\t  [P] - Parallel.");
	_MSGN("\t[ESC] - exit.");
}

static bool	add_is_valid_to_colorize(t_env *env, int *zvalue)
{
	point	p;

	p.y = NEG;
	*zvalue = (**(env->raw)).z;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			if (env->raw[p.y][p.x].rgb != IRGB_WHITE)
				return (false);
			else if (*zvalue < env->raw[p.y][p.x].z)
				*zvalue = env->raw[p.y][p.x].z;
	return (true);
}

void		fdf_add_colored_map(t_env *env)
{
	point	p;
	int		max_zvalue;
	int		colors_values[2];

	if (!add_is_valid_to_colorize(env, &max_zvalue))
		return ;
	*colors_values = max_zvalue / 3;
	colors_values[1] = *colors_values * 2;
	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			if (env->raw[p.y][p.x].z <= MAP_UNDER_UNDERWORLD)
				env->raw[p.y][p.x].rgb = IRGB_MAPUNDERWORLD_SPACE;
			else if (env->raw[p.y][p.x].z <= ZERO)
				env->raw[p.y][p.x].rgb = IRGB_MAPUNDERWORLD_WATER;
			else if (env->raw[p.y][p.x].z <= *colors_values)
				env->raw[p.y][p.x].rgb = IRGB_MAPBOTTOM_GRASS_GREEN;
			else if (env->raw[p.y][p.x].z > *colors_values
					&& env->raw[p.y][p.x].z <= colors_values[1])
				env->raw[p.y][p.x].rgb = IRGB_MAPMIDDLE_LAND_BROWN;
}
