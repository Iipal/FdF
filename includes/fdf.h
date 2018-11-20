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

# define WIN_X	1920
# define WIN_Y	1080

# define _MSG(msg) ft_putendl(msg)
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_V(ex) if (!(ex)) return
# define _NOTIS_F(ex) if (!(ex)) return (false)
# define _NOTIS_N(ex) if (!(ex)) return (NULL)

enum	e_bool
{
	false = 0,
	true
};

# define _BOOL typedef enum e_bool	bool

_BOOL;


typedef struct	s_file
{
	string	*tab;
	size_t	lines;
}				t_file;

t_file			*readnvalid(cstring file_name);

#endif
