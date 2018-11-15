/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:40:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/13 16:40:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map			*readnvalid_map(string map_name)
{
	t_map	*out;

	_NOTIS_N(out = dllist_new_empty());
	if (map_name)
		;
	return (out);
}
