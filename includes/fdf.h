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
# include <fcntl.h>
# include <mlx.h>

/*
**	'pj_read' for save all data from 'file_name' to simple two dimensional array.
*/

string			*pj_fileread(cstring file_name);

/*
**	Structure 's_matrix' & functions to save all data from file in program.
**
**	's_matrix' used like a two dimensional array (t_matrix **matrix).
*/

typedef struct	s_matrix
{
	int	z;
	int	rgb;
}				t_matrix;

/*
**	'pj_savenvalid' for save all data from 'file'
**		to our two dimensional array of 's_matrix'.
*/

t_matrix		**pj_savenvalid(string *file);

/*
**	Two global variables for save height and width of
**		our 's_matrix' two dimensional array.
*/

size_t	g_matrix_y;
size_t	g_matrix_x;

/*
**	Structure 's_mlx' & functions to manipulate with MiniLibX library.
*/

typedef struct	s_mlx
{
	pvoid	mlx;
	pvoid	win;
}				t_mlx;

/*
**	'pj_mlx_init' for initial 's_mlx' scopes & create graphic windows.
*/

t_mlx			*pj_mlx_init(cstring tittle);

#endif
