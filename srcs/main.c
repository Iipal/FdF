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
#include "../includes/matrix_list.h"

void	ft_show_matrix(t_matrix **m)
{
	int	i;
	int	j;

	i = ZERO;
	while (i < g_matrix_y)
	{
		j = ZERO;
		while (j < g_matrix_x)
		{
			printf("%d | %d\n", m[i][j].y, m[i][j].x);
			++j;
		}
		++i;
		printf("\n");
	}
}

void	show_ml(t_matrix_list *ml)
{
	printf("z: %lf y: %lf x: %lf\tcolor: %lu", ml->z, ml->p.y, ml->p.x, ml->rgb);
}

int		main(int argc, cstring argv[])
{
	string		*file;
	t_matrix	**matrix;
	t_mlx		*mlx;
	t_matrix_list	*ml;

	--argc;
	++argv;
	ml = ml_new();
	show_ml(ml);
	_NOTIS_MSG("Usage: ./fdf <map_name>", !(!argc || argc > 1));
	_NOTIS_MPE("Invalid file", file = pj_file_read(*argv));
	_NOTIS_MSG("In-validating map error.", matrix = pj_matrix_save(file));
	_NOTIS_MSG("MLX initialization error.", mlx = pj_mlx_init(*argv));
	pj_mlx_draw_matrix(mlx, matrix);
	ft_show_matrix(matrix);
	pj_file_free(file);
	pj_matrix_free(matrix);
	mlx_loop(mlx->win);
}
