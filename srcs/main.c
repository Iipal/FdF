/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:56:15 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/13 11:56:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, string *argv)
{
	t_map	*map;

	argc--;
	argv++;
	_NOTIS_MSG(argc, "usage: ./fdf <map_name>");
	_NOTIS_MSG(argc < 2, "usage: ./fdf <map_name>");
	_NOTIS_MSG(map = readnvalid_map(*argv), "failure map reading.");
	_NOTIS_MSG(init_mlx(map, *argv), "failure mlx init.");
}
