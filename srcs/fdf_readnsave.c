/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_readnsave.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:01:19 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/28 23:37:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

/*
**	The 'fdf_file_readnsave_env' function is at the bottom.
**
**		'fdf_file_readnsave_env' - Function for file reading and
**									saving data from it to
**									main environmnet structure.
**
**		'add_numbers_inline' - Function for find how much is numbers
**								and colors in one line of "file".
**
**		'add_save_tomatrix' - Save data from "file" in environment
**								two-dimensioanl matrix.
**
**		'add_line_tomatrix' - Function for saving all numbers and colors
**								to environment two-dimensioanl matrix.
*/

static int		add_numbers_inline(string line)
{
	string	temp_digits;
	int		out;
	int		digits;

	out = ZERO;
	while (*line)
	{
		if (ft_isdigit(*line) || *line == V_NEGS)
		{
			temp_digits = ft_itoa(ft_atoi(line));
			digits = ft_strlen(temp_digits);
			ft_strdel(&temp_digits);
			(line[digits] != '\0') ? (line += digits) : (line += --digits);
			if (*line == V_HEXS)
			{
				_NOTIS_F(ft_strnstr(line, V_HEX, 3));
				while (*line && !ft_isblank(*line))
					++line;
			}
			++out;
		}
		*line ? ++line : 0;
	}
	return (out);
}

static bool		add_line_tomatrix(string line, t_matrix *matrix,
									int matrix_x, int y)
{
	string	temp_digits;
	int		digits;
	int		x;

	x = NEG;
	while (*line && x < matrix_x)
	{
		if ((ft_isdigit(*line) || *line == V_NEGS) && (++x > -1))
		{
			matrix[x] = (t_matrix){y, x, ft_atoi(line), IRGB_WHITE};
			temp_digits = ft_itoa(matrix[x].z);
			digits = ft_strlen(temp_digits);
			ft_strdel(&temp_digits);
			(line[digits] != '\0') ? (line += digits) : (line += --digits);
			if (*line == V_HEXS)
			{
				_NOTIS_MSG(E_HEX, matrix[x].rgb = ft_atoi_base(line + 3, HEX));
				while (*line && !ft_isblank(*line))
					++line;
			}
		}
		*line ? ++line : 0;
	}
	return (true);
}

static bool		add_save_tomatrix(strtab file, t_env *env)
{
	int			y;
	int			line_len;

	y = NEG;
	line_len = ZERO;
	_NOTIS_F(env->raw = (t_matrix**)malloc(sizeof(t_matrix*) * env->my));
	_NOTIS_F(env->mx = add_numbers_inline(*file));
	while (++y < env->my)
	{
		_NOTIS_F(env->raw[y] = (t_matrix*)malloc(sizeof(t_matrix) * env->mx));
		line_len = add_numbers_inline(file[y]);
		if (line_len != env->mx || !line_len)
		{
			ft_putstr(E_IMAP);
			fdf_free_file(&file, env->my);
			fdf_free_matrix(&(env->raw), y + 1);
			fdf_free_env(&env);
			return (false);
		}
		_NOTIS_F(add_line_tomatrix(file[y], env->raw[y], env->mx, y));
	}
	fdf_free_file(&file, env->my);
	return (true);
}

static bool		add_valid_temp_line(string line, strtab file, int lines)
{
	if (*line != '-' && (!add_numbers_inline(line)
		|| (!ft_isdigit(*line) && !ft_isblank(*line))))
	{
		ft_strdel(&line);
		fdf_free_file(&file, lines);
		return (false);
	}
	return (true);
}

bool			fdf_file_readnsave_env(cstring file_name, t_env *env)
{
	string	gnl_temp;
	strtab	file;
	int		fd;
	int		i;

	_NOTIS_F(!(!(fd = open(file_name, O_RDONLY)) || fd < 0));
	while (ft_gnl(fd, &gnl_temp) > ZERO && ++(env->my))
		ft_strdel(&gnl_temp);
	close(fd);
	_NOTIS_MSG(E_IMAP, env->my);
	_NOTIS_F(file = (strtab)malloc(sizeof(string) * env->my));
	_NOTIS_F(fd = open(file_name, O_RDONLY));
	i = ZERO;
	while (ft_gnl(fd, &gnl_temp) > ZERO)
	{
		_NOTIS_F(add_valid_temp_line(gnl_temp, file, i));
		file[i++] = ft_strdup(gnl_temp);
		ft_strdel(&gnl_temp);
	}
	_NOTIS_F(add_save_tomatrix(file, env));
	return (true);
}
