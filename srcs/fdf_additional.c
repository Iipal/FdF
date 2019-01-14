/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_additional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:10:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/14 15:10:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

bool		fdf_add_valid_values_on_map(t_env *env)
{
	point	p;

	if (env->mx > __INT_MAX__ || env->mx < INT32_MIN)
		return (false);
	if (env->my > __INT_MAX__ || env->my < INT32_MIN)
		return (false);
	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			if (((long)env->raw[p.y][p.x].z * ZOOM_MAX) > INT32_MAX
				|| ((long)env->raw[p.y][p.x].z * ZOOM_MAX) < INT32_MIN)
				return (false);
	return (true);
}

void		fdf_add_print_usage(void)
{
	_MSGN("\t[W | A | S | D] or Arrows for moving.");
	_MSGN("\t[+] & [-] on [numpad | keyboard] for zooming.");
	_MSGN("\t[I | P] - projections switch.");
	_MSGN("\t\t[I] - Isometric.");
	_MSGN("\t\t[P] - Perspective.");
	_MSGN("\t[ESC] - exit.");
	_MSGN("\t[C] - bonus.");
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
	colors_values[1] = *colors_values + *colors_values;
	p.y = NEG;
	while (++(p.y) < env->my && (p.x = NEG))
		while (++(p.x) < env->mx)
			if (env->raw[p.y][p.x].z < ZERO)
				env->raw[p.y][p.x].rgb = IRGB_MAPUNDERWORLD_WATER;
			else if (env->raw[p.y][p.x].z <= *colors_values)
				env->raw[p.y][p.x].rgb = IRGB_MAPBOTTOM_GRASS_GREEN;
			else if (env->raw[p.y][p.x].z > *colors_values
					&& env->raw[p.y][p.x].z <= colors_values[1])
				env->raw[p.y][p.x].rgb = IRGB_MAPMIDDLE_LAND_BROWN;
}
