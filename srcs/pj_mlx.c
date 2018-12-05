/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:45:51 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 14:25:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	*pj_mlx_init(cstring file)
{
	t_mlx	*out;

	_NOTIS_N(out = (t_mlx*)malloc(sizeof(t_mlx)));
	_NOTIS_N(out->mlx = mlx_init());
	_NOTIS_N(out->win = mlx_new_window(out->mlx, WIN_X, WIN_Y, (string)file));
	return (out);
}
