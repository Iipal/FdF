/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:48:28 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/06 18:18:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

/*
**	Main constantes for ease of use:
**
**		'WIN_X' & 'WIN_Y' is window size constantes. (2:1 Aspect ratio)
**
**		'IRGB_WHITE' is Int RGB WHITE color.
**
**		'PI' is just Pi value.
**
**		'NEG', 'ZERO' & 'HEX' is just simple values.
*/

# define WIN_X			2000
# define WIN_Y			1000

# define IRGB_WHITE		16777215

# define PI				3.141592

# define NEG			-1
# define ZERO			0

# define HEX			16

# define MOVE_INC		10

# define ZOOM_INC		2
# define ZOOM_MIN		5
# define ZOOM_DEF		13
# define ZOOM_MAX		255

/*
**	Simple MAC keyboard decimal values in constantes:
*/

# define ESC			53

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_RIGHT	124
# define ARROW_LEFT		123

# define PLUS_NUMPAD	69
# define MINUS_NUMPAD	78
# define PLUS_KEYBOARD	24
# define MINUS_KEYBOARD	27

/*
**	Macroses:
*/

# define _MSG(msg)	ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)
# define _ABS(var) ((var) < 0) ? -(var) : (var)

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

# define _MATRIX typedef t_matrix**	matrix

_MATRIX;

typedef struct	s_fdf_environment
{
	int			matrix_y;
	int			matrix_x;
	uchar		zoom;
	pvoid		mlx;
	pvoid		win;
	matrix		m;
	matrix		buff;
}				t_env;

t_env			*fdf_file_readnsave_env(cstring file_name);
void			fdf_free_file(string *file, int lines);

bool			fdf_rendering(t_env *env);

typedef struct	s_point
{
	int	y;
	int	x;
}				t_p;

typedef struct	s_mlxncolor
{
	pvoid	mlx;
	pvoid	win;
	int		color;
}				t_mnc;

typedef struct	s_double_points
{
	t_p	p1;
	t_p	p2;
}				t_dp;

typedef struct	s_mlx
{
	pvoid	mlx;
	pvoid	win;
}				t_mlx;

void			fdf_bdrawing(matrix m, int matrix_y, int matrix_x, t_mlx mlx);
void			fdf_key_hooks(t_env *env);

void			fdf_free_env(t_env *env);

#endif
