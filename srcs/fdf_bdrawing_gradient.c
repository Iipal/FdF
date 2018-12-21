/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bdrawing_gradient.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:12:15 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/21 23:59:35 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_find_gradient_len(int delta, int point, int xy)
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

int	*fdf_bdrawing_gradient(t_g gradient, int line_len)
{
	t_rgb	diff;
	t_rgb	start;
	t_rgb	end;
	int		*out_rgb;
	int		i;

	i = NEG;
	start = (t_rgb){gradient.start >> 16, (gradient.start >> 8) & 0xff,
					gradient.start & 0xff};
	end = (t_rgb){gradient.end >> 16, (gradient.end >> 8) & 0xff,
					gradient.end & 0xff};
	diff = (t_rgb) {start.r - end.r, start.b - end.b, start.g - end.g};
	out_rgb = (int*)malloc(sizeof(int) * line_len);
	while (++i < line_len)
		out_rgb[i] = ((start.r - (diff.r / (i + 1))) << 16)
					| ((start.g - (diff.g / (i + 1))) << 8)
					| (start.b - (diff.b / (i + 1)));
	return (out_rgb);
}
