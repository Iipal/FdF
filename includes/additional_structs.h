/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:38:39 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 13:49:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_STRUCTS_H
# define ADDITIONAL_STRUCTS_H
# include "fdf.h"

typedef t_point	t_p;

typedef struct	s_double_points
{
	t_p	p1;
	t_p p2;
}				t_dp;

typedef	struct	s_mlxncolor
{
	t_mlx	*mlx;
	int		color;
}				t_mlxncolor;

typedef struct	s_mlxnmatrix
{
	t_mlx		*mlx;
	t_matrix	**m;
}				t_mnm;

void			pj_mnm_free(t_mnm *mnm);

#endif
