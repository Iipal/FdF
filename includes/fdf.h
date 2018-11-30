/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:57:07 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/13 11:57:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "defines.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

/*
**	"defines.h" - All macroses & constantes what will used in this program.
**	<mlx.h> - MiniLibX. School42 private project for students,
**			created by initiators of this schools.
**
**
**	'pj_file_read' for save all data from 'file_name' to
**			simple two-dimensional character array(in future "file").
**
**	'pj_free_file' for delete all data in "file".
*/

string			*pj_file_read(cstring file_name);
void			pj_file_free(string *file);

/*
**	Structure 'struct s_matrix'(in future 't_matrix') &
**			functions to save all data from file to 't_matrix'.
**
**	't_matrix' used like a dynamic two-dimensional array
**			(in future 't_matrix **matrix').
*/

typedef struct	s_matrix
{
	int	y;
	int	x;
	int	z;
	int	rgb;
}				t_matrix;

/*
**	'pj_matrix_save' for save all data from "file" to 't_matrix **matrix'.
**
**	'pj_matrix_free' for delete all data in 't_matrix **matrix'.
*/

t_matrix		**pj_matrix_save(string *file);
void			pj_matrix_free(t_matrix **matrix);

/*
**	Two global variables for save height and width of our 't_matrix **matrix'.
*/

int	g_matrix_y;
int	g_matrix_x;

/*
**	Structure 'struct s_mlx'(in future 't_mlx') &
**			functions to manipulate with MiniLibX library.
*/

typedef struct	s_mlx
{
	pvoid	mlx;
	pvoid	win;
	pvoid	img;
}				t_mlx;

/*
**	'pj_mlx_init' for initializing 't_mlx' scopes & create graphic window.
**
**	'pj_mlx_draw_matrix' for drawing matrix and lines between points
**			in mlx window, using bresenham algorithm.
*/

t_mlx			*pj_mlx_init(cstring tittle);
void			pj_mlx_draw_matrix(t_mlx *mlx, t_matrix **m);
void			pj_appscale_xy(t_matrix **m, int value);
void			pj_rotare_x(t_matrix **m);
void			pj_rotare_y(t_matrix **m);

typedef struct	s_point
{
	int	y;
	int	x;
}				t_point;

#endif
