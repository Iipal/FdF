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

#include "../../includes/fdf.h"

t_mlx	*pj_mlx_init(cstring tittle)
{
	t_mlx	*out;

	_NOTIS_N(out = (t_mlx*)malloc(sizeof(t_mlx)));
	_NOTIS_N(out->mlx = mlx_init());
	_NOTIS_N(out->win = mlx_new_window(out->mlx,
					WIN_X, WIN_Y, (string)tittle));
	return (out);
}
