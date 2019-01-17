/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:48:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/17 17:49:28 by tmaluh           ###   ########.fr       */
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


# define WIN_X		2000
# define WIN_Y		1000

# define WIN_EXT	17
# define WIN_EXTM	(1L << 17)

# define MOUSE_MASK	0
# define MOUSE_DOWN	4
# define MOUSE_UP	5
# define MOUSE_MOVE	6

# define MLEFT_BUTTON	1
# define MRIGHT_BUTTON	2
# define MTHIRD_BUTTON	3
# define MSCROLL_DOWN	4
# define MSCROLL_UPS	5
# define MSCROLL_LEFT	6
# define MSCROLL_RIGHT	7

# define PI			3.141592

# define INT_MAX	2147483647
# define INT_MIN	(-INT_MAX-1)

# define NEG		-1
# define ZERO		0

# define P_ISO		1
# define P_PAR		2

# define HEX		16

# define SHIFT_INC	15

# define ROT_MIN	0.0
# define ROT_INC	6.66
# define ROT_MAX	360.0

# define ZOOM_INC	1
# define ZOOM_MIN	1
# define ZOOM_DEF	15
# define ZOOM_MAX	128

# define E_USAGE	"Usage: ./fdf <map_name>"
# define E_ALLOC	"Where is memory, pal ?"
# define E_FILER	"File reading error"

# define E_EMAP		"\tERROR: Empty map \\ "
# define E_IMAP		"\tERROR: Invalid map \\ "
# define E_HEX		"\tERROR: Invalid HEX code or you put black color \\ "

# define V_HEX		",0x"
# define V_HEXS		','
# define V_NEGS		'-'

# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS_MSG(msg, ex) if (!(ex)) { _MSG(msg); return (false); }
# define _NOTIS_MSGN(msg, ex) if (!(ex)) { _MSGN(msg); return (false); }
# define _NOTIS_MPE(msg, ex) if (!(ex)) { perror(msg); return (false); }
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)

# define _ISARGS(ac, av) {--ac;++av;_NOTIS_MSGN(E_USAGE,!(!ac || ac > 1));}

# define _ABS(var) ((var) < 0) ? -(var) : (var)
# define _RAD(deg) (((deg) * PI) / 180.0)
# define _COSR(angle) cos(_RAD(angle))
# define _SINR(angle) sin(_RAD(angle))

# define _ERR _MSGN(E_IMAP);
# define ISMAX(n) if (((long)(n)*ZOOM_MAX)>INT_MAX){_ERR;return (false);}
# define ISMIN(n) else if (((long)(n)*ZOOM_MAX)<INT_MIN){_ERR;return (false);}
# define ISVALIDZ(n) ISMAX(n) ISMIN(n)

# define _Y env->buff[p.y][p.x].y
# define _X env->buff[p.y][p.x].x
# define _Z env->buff[p.y][p.x].z

enum	e_bool { false, true };

# define _BOOL	typedef enum e_bool	bool
# define _ITAB	typedef int**		itab
# define _IARR	typedef int*		iarr

_BOOL;
_ITAB;
_IARR;

typedef struct	s_matrix
{
	float	y;
	float	x;
	float	z;
	int		rgb;
}				t_matrix;

typedef struct	s_point
{
	short	y;
	short	x;
}				t_p;

# define _POINT typedef t_p	point

_POINT;

typedef struct	s_fpoint
{
	float	y;
	float	x;
}				t_fp;

# define _FPOINT typedef t_fp	fpoint

_FPOINT;

typedef struct	s_3d_point
{
	float	y;
	float	x;
	float	z;
}				t_3d_p;

typedef struct	s_isrender
{
	int		is_color;
	float	is_roty;
	float	is_rotx;
	uchar	is_zoom;
	uchar	is_project;
	short	is_shifty;
	short	is_shiftx;
	bool	is_refresh_buff:1;
	bool	is_frog:1;
}				t_isrender;

typedef struct	s_mouse
{
	bool	pres;
	fpoint	last;
	fpoint	curr;
}				t_mouse;

typedef struct	s_fdf_environment
{
	t_matrix	**raw;
	t_matrix	**buff;
	pvoid		mlx;
	pvoid		win;
	pvoid		img;
	itab		frog;
	uchar		zoom:7;
	int			color;
	int			my;
	int			mx;
	short		dy;
	short		dx;
	float		sy;
	float		sx;
	float		roty;
	float		rotx;
	t_3d_p		fcenter;
	iarr		screen;
	bool		is_frog_render:1;
	uchar		project:2;
	t_isrender	isr;
	t_mouse		mouse;
}				t_env;

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

bool			fdf_file_readnsave_env(cstring file_name, t_env *env);

void			fdf_rendering(t_env *env);

bool			fdf_init_render_buff(t_env *env);
void			fdf_refresh_buff(t_env *env);
void			fdf_set_image_pixel(point p, int color, t_mlx *mlx);
void			fdf_refresh_image(t_env *env);
void			fdf_zooming_buff(t_env *env);
void			fdf_move_buff(t_env *env, float xinc, float yinc);
void			fdf_center_of_buff(t_env *env);
void			fdf_rotare_buff(t_env *env);

void			fdf_isometric(t_env *env);

void			fdf_bdrawing(t_matrix **m, t_p mxy, t_mlx mlx);
iarr			fdf_gradient(t_g *g, int glen);
int				fdf_glen(int delta, int p, int xy);

int				fdf_mouse_press(int button, int x, int y, t_env *env);
int				fdf_mouse_release(int button, int x, int y, t_env *env);
int				fdf_mouse_moves(int x, int y, t_env *env);

int				fdf_keys_hook(int key, t_env *env);
int				fdf_khook_killwindow(t_env *env);

void			fdf_add_print_usage(void);
void			fdf_add_colored_map(t_env *env);

void			fdf_free_env(t_env **env);
void			fdf_free_matrix(t_matrix ***m, int matrix_y);
void			fdf_free_file(strtab *file, int lines);

#endif
