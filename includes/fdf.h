/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:48:28 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/12 17:01:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
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

# define PI				3.141592

# define NEG			-1
# define ZERO			0

# define HEX			16

# define MOVE_INC		15

# define ROT_INC		32

# define ZOOM_INC		2
# define ZOOM_MIN		5
# define ZOOM_DEF		13
# define ZOOM_MAX		255

/*
**	Simple MAC keyboard decimal values in constantes:
*/

# define ESC			53

# define KEY_R			15
# define KEY_T			17
# define KEY_Y			16
# define KEY_F			3
# define KEY_G			5
# define KEY_H			4

# define KEY_C			8

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
**	\____ Info include in README.md
*/

# define _MSG(msg) ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)
# define _ABS(var) ((var) < 0) ? -(var) : (var)
# define _RAD(deg) (((deg) * PI) / 180.0)

/*
**	Additional code functional for program:
**	\____ For boolean data type in C.
*/

enum	e_bool
{
	false,
	true
};

# define _BOOL typedef enum e_bool	bool

_BOOL;

/*
**	Bonus part:
**	\____ 5 Colors constantes for changing grid default color.
*/

# define IRGB_GRAY			3355443
# define IRGB_WHITE			16777215
# define IRGB_LIME			15007539
# define IRGB_CHERRY		15865942
# define IRGB_AQUA			7273983

/*
**	Main struct's definitions and functions prototypes
**	\____ main struct definitions:
**		| 'my' - counter Y-positions. (max Y-positions)
**		| 'mx' - counter X-positions. (max X-positions)
**		| 'color' - default grid color. (bonus)
**		| 'zoom' - current zoom value.
**		| 'mlx' && 'win' - for init mlx and mlx_window.
**		| 'm' - raw matrix with data from file.
*/

typedef struct	s_matrix
{
	int	y;
	int	x;
	int	z;
	int	rgb;
}				t_matrix;

typedef struct	s_fdf_environment
{
	int			my;
	int			mx;
	int			cy;
	int			cx;
	int 		color;
	uchar		zoom;
	pvoid		mlx;
	pvoid		win;
	t_matrix	**m;
	t_matrix	**buff;
}				t_env;

bool			fdf_file_readnsave_env(cstring file_name, t_env *env);
void			fdf_free_file(string *file, int lines);

typedef struct	s_isrender
{
	bool	is_center;
	int		is_zoomed;
	int		is_color;
	int		is_shiftx;
	int		is_shifty;
}				t_isrender;

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

void			fdf_bdrawing(t_env *env);
void			fdf_key_hooks(t_env *env);

void			fdf_xmove(t_env *env, int inc);
void			fdf_ymove(t_env *env, int inc);

void			fdf_free_env(t_env *env);

void			fdf_xrotare(t_env *env, int inc);
void			fdf_yrotare(t_env *env, int inc);
void			fdf_zrotare(t_env *env, int inc);

#endif
