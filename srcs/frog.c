/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:44:34 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/14 17:54:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

static int		**bonus_init_frog(void)
{
	int	**out_frog;
	int	y;

	y = NEG;
	_NOTIS_N(out_frog = (int**)malloc(sizeof(int*) * FHEIGHT));
	while (++y < FHEIGHT)
		_NOTIS_N(out_frog[y] = (int*)malloc(sizeof(int) * FWIDTH));
	out_frog[0][0] = IRGB_BLACK;
	out_frog[0][1] = IRGB_BLACK;
	out_frog[0][2] = IRGB_WHITE;
	out_frog[0][3] = IRGB_WHITE;
	out_frog[0][4] = IRGB_WHITE;
	out_frog[0][5] = IRGB_WHITE;
	out_frog[0][6] = IRGB_BLACK;
	out_frog[0][7] = IRGB_BLACK;
	out_frog[0][8] = IRGB_BLACK;
	out_frog[0][9] = IRGB_BLACK;
	out_frog[0][10] = IRGB_BLACK;
	out_frog[0][11] = IRGB_WHITE;
	out_frog[0][12] = IRGB_WHITE;
	out_frog[0][13] = IRGB_WHITE;
	out_frog[0][14] = IRGB_WHITE;
	return (out_frog);
}

