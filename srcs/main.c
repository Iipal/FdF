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

int		main(int argc, cstring argv[])
{
	t_file		*file;
	t_matrix	**matrix;

	--argc;
	++argv;
	file = NULL;
	_NOTIS_MSG("Usage: ./fdf <map_name>", !(!argc || argc > 1));
	_NOTIS_MPE("Invalid file", (file = f_read(*argv)));
	_NOTIS_MSG("Invalid map", (matrix = f_savenvalid(file)));
}