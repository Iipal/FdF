/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bdrawing_gradient.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:12:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/08 18:49:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_glen(int delta, int p, int xy)
{
	int	gradient_len;

	gradient_len = ZERO;
	while (((delta > 0) ? (xy <= p) : (xy >= p)))
	{
		++gradient_len;
		(delta > 0) ? ++xy : --xy;
	}
	return (gradient_len);
}

iarr	fdf_gradient(t_g *g, int glen)
{
	t_rgb	diff;
	t_rgb	start;
	iarr	rgb;
	int		i;

	i = NEG;
	rgb = (iarr)malloc(sizeof(int) * glen);
	if (g->start == g->end)
	{
		while (++i < glen)
			rgb[i] = g->start;
		return (rgb);
	}
	start = (t_rgb){g->start >> 16, (g->start >> 8) & 0xff, g->start & 0xff};
	diff = (t_rgb){(g->end >> 16) - start.r, ((g->end >> 8) & 0xff) - start.g,
					(g->end & 0xff) - start.b};
	while (++i < glen)
	{
		start = (t_rgb){start.r + diff.r / glen, start.g + diff.g / glen,
						start.b + diff.b / glen};
		rgb[i] = ((int)start.r << 16) | ((int)start.g << 8) | ((int)start.b);
	}
	return (rgb);
}
