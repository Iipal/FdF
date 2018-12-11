/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_readnsave.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:01:19 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/11 13:46:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	The 'fdf_file_readnsave_env' function is at the bottom.
**
**		'fdf_file_readnsave_env' - Function for file reading and
**		\____ saving data from it to main environmnet structure.
**			| - Called from the 'main' function. (main.c)
**
**		'add_save_tomatrix' - Save data from "file" in environment
**		\____ two-dimensioanl matrix.
**			| - Additional function for 'fdf_file_readnsave_env'.
**
**		'add_numbers_inline' - Function for find how much is numbers
**		\____ and colors in one line of "file".
**			| - Additional function for 'add_save_tomatrix'.
**
**		'add_line_tomatrix' - Function for saving all numbers and colors
**		\____ to environment two-dimensioanl matrix.
**			| - Additional function for 'add_save_tomatrix'.
*/

static bool		add_line_tomatrix(string line, t_matrix *matrix,
								int current_y, int matrix_x)
{
	int	x;
	int	digits;

	x = ZERO;
	while (*line && x < matrix_x)
	{
		if ((ft_isdigit(*line) || *line == '-') && !(digits = ZERO))
		{
			matrix[x].y = current_y;
			matrix[x].x = x;
			matrix[x].rgb = IRGB_WHITE;
			matrix[x].z = ft_atoi(line);
			digits = ft_strlen(ft_itoa(matrix[x].z));
			(line[digits] != '\0') ? (line += digits) : (line += (digits - 1));
			if (*line == ',')
			{
				_NOTIS_F(matrix[x].rgb = ft_atoi_base(line + 3, HEX));
				while (*line && !ft_isblank(*line))
					++line;
			}
			++x;
		}
		*line ? ++line : 0;
	}
	return (true);
}

static int		add_numbers_inline(string line)
{
	int	numbers;
	int	digits;

	numbers = ZERO;
	while (*line)
	{
		if (ft_isdigit(*line) || *line == '-')
		{
			digits = ft_strlen(ft_itoa(ft_atoi(line)));
			(line[digits] != '\0') ? (line += digits) : (line += (digits - 1));
			if (*line == ',')
				while (*line && !ft_isblank(*line))
					++line;
			++numbers;
		}
		*line ? ++line : 0;
	}
	return (numbers);
}

static matrix	add_save_tomatrix(string *file, int matrix_y, int *matrix_x)
{
	matrix		m;
	int			y;

	y = NEG;
	_NOTIS_N(m = (matrix)malloc(sizeof(t_matrix*) * matrix_y));
	_NOTIS_N(*matrix_x = add_numbers_inline(*file));
	while (++y < matrix_y)
	{
		_NOTIS_N(add_numbers_inline(file[y]) == *matrix_x);
		_NOTIS_N(m[y] = (t_matrix*)malloc(sizeof(t_matrix) * *matrix_x));
		_NOTIS_N(add_line_tomatrix(file[y], m[y], y, *matrix_x));
	}
	fdf_free_file(file, matrix_y);
	return (m);
}

bool			fdf_file_readnsave_env(cstring file_name, t_env *env)
{
	string	gnl_temp;
	string	*file;
	int		fd;
	int		i;

	i = ZERO;
	_NOTIS_F(fd = open(file_name, O_RDONLY));
	while (ft_gnl(fd, &gnl_temp) > ZERO && ++(env->matrix_y))
		ft_strdel(&gnl_temp);
	close(fd);
	_NOTIS_F(env->matrix_y);
	_NOTIS_F(file = (string*)malloc(sizeof(string) * env->matrix_y));
	_NOTIS_F(fd = open(file_name, O_RDONLY));
	while (ft_gnl(fd, &gnl_temp) > ZERO)
	{
		file[i++] = ft_strdup(gnl_temp);
		ft_strdel(&gnl_temp);
	}
	_NOTIS_F(env->m = add_save_tomatrix(file,
		env->matrix_y, &(env->matrix_x)));
	return (true);
}
