/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:48:28 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/25 20:45:49 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# ifdef __APPLE__
#  include "macos_keys.h"
# endif

# ifdef __linux__
#  include "linux_keys.h"
# endif

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

# define WIN_X			1280
# define WIN_Y			640

# define PI				3.141592

# define NEG			-1
# define ZERO			0

# define P_ISO			1
# define P_PER			2
# define P_RAW			3

# define HEX			16

# define SHIFT_INC		15

# define ROT_MIN		0.0
# define ROT_INC		5.0
# define ROT_MAX		360.0

# define ZOOM_INC		2
# define ZOOM_MIN		3
# define ZOOM_DEF		15
# define ZOOM_MAX		255

# define E_USAGE	"Usage: ./fdf <map_name>"
# define E_ALLOC	"Where is memory, pal ?"
# define E_FILER	"File reading error"

# define E_IPER	"\tWarning: Perspective doesn't work with < 0 values Z."
# define E_EMAP	"\tERROR: Empty map \\"
# define E_IMAP	"\tERROR: Invalid map \\"
# define E_HEX	"\tERROR: Invalid HEX code or you put black color \\"

# define V_HEX	",0x"
# define V_HEXS	','
# define V_NEGS	'-'

/*
**	Macroses:
**	\____ Info include in README.md
*/

# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_MSGN(msg, ex) if (!(ex)) { _MSGN(msg); return (false); }
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

# define _BOOL	typedef enum e_bool	bool
# define _ITAB	typedef int**		itab

_BOOL;
_ITAB;

/*
**	Bonus part:
**	\____ 5 Colors constantes for changing grid default color.
*/

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
	int	y:16;
	int	x:16;
	int	z;
	int	rgb;
}				t_matrix;

typedef struct	s_fdf_environment
{
	t_matrix	**raw;
	t_matrix	**render;
	pvoid		mlx;
	pvoid		win;
	pvoid		img;
	itab		frog;
	uchar		zoom;
	int			color;
	int			my;
	int			mx;
	int			dy:16;
	int			dx:16;
	float		sy;
	float		sx;
	float		roty;
	float		rotx;
	float		rotz;
	bool		is_frog_render:1;
	uchar		project:8;
}				t_env;

typedef struct	s_isrender
{
	uchar	is_zoomed;
	uchar	is_project;
	float	is_roty;
	float	is_rotx;
	float	is_rotz;
	bool	is_isr_init:1;
	bool	is_perspective:1;
	bool	is_render:1;
	bool	is_center:1;
	bool	is_frog:1;
	int		is_shiftx:16;
	int		is_shifty:16;
	int		is_color;
}				t_isrender;

typedef struct	s_point
{
	int	y:16;
	int	x:16;
}				t_p;

# define _POINT typedef t_p	point

_POINT;

typedef struct	s_gradient
{
	int	start;
	int	end;
}				t_g;

typedef struct	s_rgb
{
	float	r;
	float	g;
	float	b;
}				t_rgb;

typedef struct	s_double_points
{
	point	p1;
	point	p2;
}				t_dp;

typedef struct	s_mlx
{
	pvoid	mlx;
	pvoid	win;
	pvoid	img;
}				t_mlx;

bool			fdf_file_readnsave_env(cstring file_name, t_env *env);
void			fdf_rendering(t_env *env);

bool			fdf_init_render_buff(t_env *env);
void			fdf_refresh_buff(t_env *env, t_isrender *isr);

void			fdf_isometric(t_env *env);
void			fdf_perspective(t_env *env);

void			fdf_bdrawing(t_matrix **m, t_p mxy, t_mlx mlx);
void			fdf_zooming(t_env *env);
int				*fdf_gradient(t_g *gradient, int line_len);
int				fdf_glen(int delta, int point, int xy);

int				fdf_keys_hook(int key, t_env *env);

void			fdf_xmove(t_env *env, float inc);
void			fdf_ymove(t_env *env, float inc);

void			fdf_xrotare(t_env *env, int inc);
void			fdf_yrotare(t_env *env, int inc);
void			fdf_zrotare(t_env *env, int inc);

void			fdf_add_valid_zoom(t_env *env);
void			fdf_add_print_usage(void);
bool			fdf_add_check_valid_perspective(t_env *env);

void			fdf_free_env(t_env **env);
void			fdf_free_matrix(t_matrix ***m, int matrix_y);
void			fdf_free_file(strtab *file, int lines);

#endif
