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
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

enum	e_bool
{
	false = 0,
	true
};

# define _BOOL typedef enum e_bool	bool

_BOOL;

# define WIN_X	1920
# define WIN_Y	1080

# define _MSG(msg) ft_putendl(msg)
# define _NOTIS_MSG(ex, msg) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_V(ex)	if (!(ex))	return
# define _NOTIS_F(ex) 	if (!(ex))	return (false)
# define _NOTIS_N(ex)	if (!(ex))	return (NULL)

typedef struct	s_pos
{
	size_t	y;
	size_t	x;
	size_t	z;
}				t_pos;

typedef struct	s_map
{
	size_t			y;
	size_t			x;
	size_t			z;
	struct s_map	*ny;
	struct s_map	*nx;
}				t_map;

t_map			*readnvalid_map(string map_name);
t_map			*dllist_new_empty(void);

bool			init_mlx(t_map *map, string map_name);

void			dllist_show_all(t_map *map);

#endif
