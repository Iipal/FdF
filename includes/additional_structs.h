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

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_double_points
{
	t_point	p1;
	t_point p2;
}				t_double_points;

#endif
