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

typedef struct	s_matrix
{
	int	z;
	int	rgb;
}				t_matrix;

typedef struct	s_file
{
	string	*tab;
	size_t	lines;
}				t_file;

size_t	g_matrix_y;
size_t	g_matrix_x;

void			pj_free_file(t_file **file);
void			pj_free_matrix(t_matrix **matrix);

t_file			*pj_read(cstring file_name);
t_matrix		**pj_savenvalid(t_file *file);

#endif
