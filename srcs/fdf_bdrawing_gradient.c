/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bdrawing_gradient.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:12:15 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/25 12:23:26 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_glen(int delta, int point, int xy)
{
	int	out_len;

	out_len = ZERO;
	while (((delta > 0) ? (xy <= point) : (xy >= point)))
	{
		++out_len;
		(delta > 0) ? ++xy : --xy;
	}
	return (out_len);
}

int	*fdf_gradient(t_g *g, int glen)
{
	t_rgb	diff;
	t_rgb	start;
	int		*out_rgb;
	int		i;

	i = NEG;
	out_rgb = (int*)malloc(sizeof(int) * glen);
	if (g->start == g->end)
	{
		while (++i < glen)
			out_rgb[i] = g->start;
		return (out_rgb);
	}
	start = (t_rgb){g->start >> 16, (g->start >> 8) & 0xff, g->start & 0xff};
	diff = (t_rgb){(g->end >> 16) - start.r, ((g->end >> 8) & 0xff) - start.g,
					(g->end & 0xff) - start.b};
	while (++i < glen)
	{
		start = (t_rgb){start.r + diff.r / glen, start.g + diff.g / glen,
						start.b + diff.b / glen};
		out_rgb[i] = ((int)start.r << 16) | ((int)start.g << 8) | ((int)start.b);
	}
	return (out_rgb);
}
