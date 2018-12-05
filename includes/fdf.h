/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:48:28 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 18:48:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define WIN_X 2000
# define WIN_Y 1000

# define IRGB_WHITE 16777215

# define NEG -1
# define ZERO 0

# define HEX 16
# define DEC 10

# define PI 3.141592

# define _MSG(msg)	ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)

enum	e_bool
{
	false,
	true
};

# define _BOOL typedef enum e_bool	bool

_BOOL;

typedef struct	s_matrix
{
	int	y;
	int	x;
	int	z;
	int	rgb;
}				t_matrix;

typedef struct	s_fdf_environment
{
	int			matrix_y;
	int			matrix_x;
	pvoid		mlx;
	pvoid		win;
	t_matrix	**matrix;
}				t_env;

t_env			*fdf_file_readnsave_tomatrix_env(cstring file);
void			fdf_file_free(string *file, int lines);

#endif
