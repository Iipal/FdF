/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:48:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/02 01:42:27 by tmaluh           ###   ########.fr       */
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

# define WIN_X			1280
# define WIN_Y			640

# define WIN_EXIT		17
# define WIN_EXIT_MASK	(1L << 17)

# define PI				3.141592

# define NEG			-1
# define ZERO			0

# define P_ISO			1
# define P_PAR			2

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

# define E_EMAP	"\tERROR: Empty map \\ "
# define E_IMAP	"\tERROR: Invalid map \\ "
# define E_HEX	"\tERROR: Invalid HEX code or you put black color \\ "

# define V_HEX	",0x"
# define V_HEXS	','
# define V_NEGS	'-'

# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_MSGN(msg, ex) if (!(ex)) { _MSGN(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)
# define _ABS(var) ((var) < 0) ? -(var) : (var)
# define _RAD(deg) (((deg) * PI) / 180.0)

# define _COS(angle) cos(_RAD(angle))
# define _SIN(angle) sin(_RAD(angle))

# define _Y env->render[p.y][p.x].y
# define _X env->render[p.y][p.x].x
# define _Z env->render[p.y][p.x].z
# define _YP env->render[p->y][p->x].y
# define _XP env->render[p->y][p->x].x
# define _ZP env->render[p->y][p->x].z

enum	e_bool
{
	false,
	true
};

# define _BOOL	typedef enum e_bool	bool
# define _ITAB	typedef int**		itab
# define _IARR	typedef int*		iarr

_BOOL;
_ITAB;
_IARR;

typedef struct	s_matrix
{
	int	y;
	int	x;
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
	short		dy;
	short		dx;
	float		sy;
	float		sx;
	float		roty;
	float		rotx;
	float		rotz;
	iarr		screen;
	bool		is_frog_render:1;
	uchar		project:8;
}				t_env;

typedef struct	s_isrender
{
	int		is_color;
	float	is_roty;
	float	is_rotx;
	float	is_rotz;
	uchar	is_zoomed;
	uchar	is_project;
	short	is_shifty;
	short	is_shiftx;
	bool	is_init:1;
	bool	is_render:1;
	bool	is_center:1;
	bool	is_frog:1;
}				t_isrender;

typedef struct	s_point
{
	short	y;
	short	x;
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
	iarr	img;
}				t_mlx;

bool			fdf_file_readnsave_env(cstring, t_env*);
void			fdf_rendering(t_env*);

bool			fdf_init_render_buff(t_env*);
void			fdf_refresh_buff(t_env*, t_isrender*);
void			fdf_set_image_pixel(point, int, t_mlx*);
void			fdf_refresh_image(t_env*);
void			fdf_zooming(t_env*);

void			fdf_isometric(t_env*);

void			fdf_bdrawing(t_matrix**, t_p, t_mlx);
iarr			fdf_gradient(t_g*, int);
int				fdf_glen(int, int, int);

int				fdf_keys_hook(int, t_env*);
int				fdf_khook_close_window(t_env *env);

void			fdf_xmove(t_env*, float);
void			fdf_ymove(t_env*, float);
void			fdf_rotare(t_env*);

void			fdf_add_valid_zoom(t_env*);
void			fdf_add_print_usage(void);

void			fdf_free_env(t_env**);
void			fdf_free_matrix(t_matrix***, int);
void			fdf_free_file(strtab*, int);

#endif
