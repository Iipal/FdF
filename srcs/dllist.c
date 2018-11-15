/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:57:52 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/14 11:57:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*dllist_new_empty(void)
{
	t_map	*out;

	_NOTIS_N(out = (t_map*)malloc(sizeof(t_map)));
	out->y = 0;
	out->x = 0;
	out->z = 0;
	out->ny = NULL;
	out->nx = NULL;
	return (out);
}
