/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_additional_corrections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:10:11 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/29 19:23:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

void	fdf_add_valid_zoom(t_env *env)
{
	point	pl;
	float	shift_y;
	float	shift_x;

	while (true)
	{
		shift_y = ((WIN_Y - ((float)env->my * env->zoom)) / 2);
		shift_x = ((WIN_X - ((float)env->mx * env->zoom)) / 2);
		pl.y = env->raw[ZERO][env->mx - 1].y * env->zoom + shift_y;
		pl.x = env->raw[ZERO][env->mx - 1].x * env->zoom + shift_x;
		if ((pl.y <= WIN_Y && pl.y >= ZERO) || (pl.x <= WIN_X && pl.x >= ZERO))
			return ;
		--(env->zoom);
	}
}

void	fdf_add_print_usage(void)
{
	_MSGN("USAGE:");
	_MSGN("\t[W | A | S | D] or Arrows for moving.");
	_MSGN("\t[+] & [-] on [numpad | keyboard] for zooming.");
	_MSGN("\t[T | G] - x rotate\n\t[Y | H] - y rotate\n\t[U | J] - z rotate.");
	_MSGN("\t[I | O | P] - projections switch.");
	_MSGN("\t\t[I] - Isometric.");
	_MSGN("\t\t[P] - Perspective.");
	_MSGN("\t[ESC] - exit.");
	_MSGN("\t[C] - bonus.");
}
