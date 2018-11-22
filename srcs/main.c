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

void	ft_show_matrix(t_matrix **m)
{
	size_t	i;
	size_t	j;

	i = NEG;
	while (++i < g_matrix_y)
	{
		j = NEG;
		while (++j < g_matrix_x)
			printf("%d ", m[i][j].z);
		printf("\n");
	}
}

int		main(int argc, cstring argv[])
{
	t_file		*file;
	t_matrix	**matrix;

	--argc;
	++argv;
	file = NULL;
	_NOTIS_MSG("Usage: ./fdf <map_name>", !(!argc || argc > 1));
	_NOTIS_MPE("Invalid file", (file = pj_read(*argv)));
	_NOTIS_MSG("Invalid map", (matrix = pj_savenvalid(file)));
	ft_show_matrix(matrix);
	pj_free_file(&file);
	pj_free_matrix(matrix);
}
