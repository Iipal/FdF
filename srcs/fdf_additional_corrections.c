/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_additional_corrections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:10:11 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/21 17:33:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_valid_zoom(t_env *env)
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
