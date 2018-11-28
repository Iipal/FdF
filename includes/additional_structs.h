/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:38:39 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/27 11:38:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_STRUCTS_H
# define ADDITIONAL_STRUCTS_H
# include "fdf.h"

/*
**	All of this structs using only for drawing matrix in 'pj_drawing.c'
*/

/*
**	'sturct s_spoint' just for saving x and y of positions.
*/

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

/*
**	'sturct s_double_points' just for saving 2 postions of 'sturct s_spoint'
*/

typedef struct	s_double_points
{
	t_point	p1;
	t_point p2;
}				t_dp;

/*
**	'sturct s_mlxncolor' just for saving mlx data and color.
*/

typedef	struct	s_mlxncolor
{
	t_mlx	*mlx;
	int		color;
}				t_mlxncolor;

#endif
