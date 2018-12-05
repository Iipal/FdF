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
	int	y;
	int	x;

	y = NEG;
	while (++y < g_matrix_y && (x = NEG))
	{
		while (++x < g_matrix_x)
			printf("%3d - %3d - %4d\t| %d\n",
				m[y][x].y, m[y][x].x, m[y][x].z, m[y][x].rgb);
		printf("\n");
	}
	printf("%d | %d\n", g_matrix_y, g_matrix_x);
}

int		main(int argc, cstring argv[])
{
	// Onlywsx
	string		*file;
	t_matrix	**matrix;
	t_mlx		*mlx;

	--argc;
	++argv;
	_NOTIS_MSG("Usage: ./fdf <map_name>", !(!argc || argc > 1));
	_NOTIS_MPE("Invalid file", file = pj_file_read(*argv));
	_NOTIS_MSG("In-validating map error.", matrix = pj_matrix_save(file));
	_NOTIS_MSG("MLX initialization error.", mlx = pj_mlx_init(*argv));
	pj_file_free(file);
	/*
	**	WTF?!?
	*/
	pj_render(mlx, matrix, DEC);
	ft_show_matrix(matrix);
	pj_matrix_free(matrix);
	mlx_loop(mlx->mlx);
}
