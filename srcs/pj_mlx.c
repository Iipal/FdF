/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:45:51 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/23 13:45:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pj_mlx_draw_image(t_mlx *mlx, t_matrix **matrix)
{
	if (matrix)
		{}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	// printf("%s\n\n\n%d | %d | %d\n", mlx_get_data_addr(mlx->img, b, s, e), *b, *s, *e);
}


t_mlx	*pj_mlx_init(cstring file)
{
	t_mlx	*out;

	_NOTIS_N(out = (t_mlx*)malloc(sizeof(t_mlx)));
	_NOTIS_N(out->mlx = mlx_init());
	_NOTIS_N(out->win = mlx_new_window(out->mlx, WIN_X, WIN_Y, (string)file));
	_NOTIS_N(out->img = mlx_new_image(out->mlx, WIN_X, WIN_Y));
	return (out);
}
