/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:15:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/18 11:43:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_set_image_pixel(point p, int color, t_mlx *mlx)
{
	if ((p.x >= ZERO && p.x < WIN_X) && (p.y >= ZERO && p.y < WIN_Y))
		mlx->img[p.y * WIN_X + p.x] = color;
}

void	fdf_refresh_image(t_env *env)
{
	ft_bzero(env->screen, sizeof(int) * WIN_X * WIN_Y);
	fdf_bdrawing(env->buff, (t_p){env->my, env->mx},
				(t_mlx){env->mlx, env->win, env->screen});
	mlx_put_image_to_window(env->mlx, env->win, env->img, ZERO, ZERO);
}
