/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bdrawing_gradient.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:12:15 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/23 18:57:55 by ipal             ###   ########.fr       */
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

int	*fdf_gradient(t_g *gradient, int gradient_len)
{
	t_rgb	diff;
	t_rgb	start;
	t_rgb	end;
	int		*out_rgb;
	int		i;

	i = NEG;
	start = (t_rgb){gradient->start >> 16, (gradient->start >> 8) & 0xff,
					gradient->start & 0xff};
	end = (t_rgb){gradient->end >> 16, (gradient->end >> 8) & 0xff,
				gradient->end & 0xff};
	diff = (t_rgb){end.r - start.r,
				end.g - start.g,
				end.b - start.b};
	out_rgb = (int*)malloc(sizeof(int) * gradient_len);
	while (++i < gradient_len)
	{
		start = (t_rgb){start.r + diff.r / gradient_len,
						start.g + diff.g / gradient_len,
						start.b + diff.b / gradient_len};
		out_rgb[i] = ((int)start.r << 16) | ((int)start.g << 8) | ((int)start.b);
	}
	return (out_rgb);
}
