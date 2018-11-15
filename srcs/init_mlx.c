/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:13:29 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/14 09:13:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	init_mlx(t_map *map, string file_name)
{
	pvoid	mlx;
	pvoid	win;

	_NOTIS_F(mlx = mlx_init());
	_NOTIS_F(win = mlx_new_window(mlx, WIN_X, WIN_Y, file_name));
	_NOTIS_F(mlx_loop(mlx));
	printf("%lu | %lu | %lu | %s\n", map->x, map->y, map->z, file_name);
	return (true);
}
