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
**	Structure 's_file' & functions to save data from a file and manipulate it.
*/

typedef struct	s_file
{
	string	*tab;
	size_t	lines;
}				t_file;

/*
**	'pj_read' for save all data from 'file_name' to 's_file'.
**
**	'pj_free_file' for delete all data in 's_file'.
*/

t_file			*pj_read(cstring file_name);
void			pj_free_file(t_file **file);

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
**
**	'pj_free_matrix' for delete all data in 's_matrix'.
*/

t_matrix		**pj_savenvalid(t_file *file);
void			pj_free_matrix(t_matrix **matrix);

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

t_mlx			*pj_mlx_init(void);

#endif
