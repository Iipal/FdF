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
	int	i;
	int	j;

	i = NEG;
	while (++i < g_matrix_y)
	{
		j = NEG;
		while (++j < g_matrix_x)
			printf("%d - %d - %d\t| %d\n",
				m[i][j].y, m[i][j].x, m[i][j].z, m[i][j].rgb);
		printf("\n");
	}
	printf("%d | %d\n", g_matrix_y, g_matrix_x);
}

int		main(int argc, cstring argv[])
{
	string		*file;
	t_matrix	**matrix;
	t_mlx		*mlx;

	--argc;
	++argv;
	_NOTIS_MSG("Usage: ./fdf <map_name>", !(!argc || argc > 1));
	_NOTIS_MPE("Invalid file", file = pj_file_read(*argv));
	_NOTIS_MSG("In-validating map error.", matrix = pj_matrix_save(file));
	_NOTIS_MSG("MLX initialization error.", mlx = pj_mlx_init(*argv));
	pj_matrix_upscale(matrix, DEC);
	pj_rotare_x(matrix);
	pj_rotare_y(matrix);
	pj_rotare_z(matrix);
	pj_mlx_draw_raw(mlx, matrix);
	// pj_mlx_draw_image(mlx, matrix);
	pj_file_free(file);
	// ft_show_matrix(matrix);
	pj_matrix_free(matrix);
	mlx_loop(mlx->mlx);
}
