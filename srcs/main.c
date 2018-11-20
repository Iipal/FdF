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
	t_file	*file;

	argc--;
	argv++;
	file = NULL;
	_NOTIS_MSG("Usage: ./fdf <map_name>", argc);
	_NOTIS_MSG("Usage: ./fdf <map_name>", argc < 2);
	_NOTIS_MSG("Error: invalid file or data in it.", (file = readnvalid(*argv)));
	size_t	i = -1;
	while (++i < file->lines)
		printf("%s\n", file->tab[i]);
}
