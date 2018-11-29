/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:34:22 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/29 09:52:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_LIST_H
# define MATRIX_LIST_H

// # include "fdf.h"

typedef struct	s_point
{
	double	y;
	double	x;
}				t_point;

typedef struct	s_matrix_list
{
	double					z;
	t_point					p;
	size_t					rgb;
	struct s_matrix_list	*y;
	struct s_matrix_list	*x;
}				t_matrix_list;

t_matrix_list	*ml_new(void);
t_matrix_list	*ml_addy(t_matrix_list *ml, t_matrix_list *(new_mly(char*)));
t_matrix_list	*ml_addx(t_matrix_list *ml, double z,
							t_point p, size_t rgb);

#endif
