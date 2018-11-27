/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_readnsave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:46:48 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/23 13:47:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

string			*pj_file_read(cstring file_name)
{
	string	*out_tab;
	string	gnl_temp;
	int		i;
	int		fd;

	gnl_temp = NULL;
	g_matrix_y = ZERO;
	_NOTIS_N(fd = open(file_name, O_RDONLY));
	_NOTIS_N(read(fd, NULL, ZERO) >= ZERO);
	while (ft_gnl(fd, &gnl_temp) > ZERO)
	{
		++g_matrix_y;
		ft_strdel(&gnl_temp);
	}
	close(fd);
	_NOTIS_FREE(out_tab = (string*)malloc(sizeof(string) * g_matrix_y),
					pj_file_free(out_tab));
	_NOTIS_FREE(fd = open(file_name, O_RDONLY), pj_file_free(out_tab));
	i = ZERO;
	while (ft_gnl(fd, &gnl_temp) > ZERO)
	{
		_NOTIS_FREE(out_tab[i++] = ft_strdup(gnl_temp), pj_file_free(out_tab));
		ft_strdel(&gnl_temp);
	}
	return (out_tab);
}

/*
**	'add_numbers_inline' additional function for 'pj_savenvalid'.
**			Used for known how much numbers in 1 line of "file".
*/

static int		add_numbers_inline(string line)
{
	int		out_numbers_counter;
	int		number_abs_temp;
	int		digits;
	long	number;

	out_numbers_counter = ZERO;
	while (*line)
	{
		if (ft_isdigit(*line) || *line == '-')
		{
			digits = ZERO;
			number = ft_atoi(line);
			number_abs_temp = _ABS(number);
			_DIGITS_IN_NUMBER(number_abs_temp);
			(digits == 0) ? (digits = 1) : digits;
			(line[digits] != '\0') ? (line += digits) : (line += (digits - 1));
			if (*line == ',')
				while (*line && !ft_isblank(*line))
					++line;
			++out_numbers_counter;
		}
		*line ? ++line : 0;
	}
	return (out_numbers_counter);
}

/*
**	'add_line_to_matrix' additional function for 'pj_savenvalid'.
**			Used for save all numbers in each 'line' of file to 'matrix[y]'.
*/

static bool		add_line_to_matrix(string line, t_matrix *matrix)
{
	int	x;
	int	digits;
	int	number_abs_temp;

	x = NEG;
	while (*line && ++x < g_matrix_x)
	{
		if ((ft_isdigit(*line) || *line == '-') && !(digits = ZERO))
		{
			matrix[x].rgb = IRGB_WHITE;
			matrix[x].z = ft_atoi(line);
			number_abs_temp = _ABS(matrix[x].z);
			_DIGITS_IN_NUMBER(number_abs_temp);
			((digits == 0) ? (digits = 1) : digits);
			(line[digits] != '\0') ? (line += digits) : (line += (digits - 1));
			if (*line == ',')
			{
				_NOTIS_F(matrix[x].rgb = ft_atoi_base(line + 3, HEX));
				while (*line && !ft_isblank(*line))
					++line;
			}
		}
		*line ? ++line : 0;
	}
	return (true);
}

t_matrix		**pj_matrix_save(string *file)
{
	t_matrix	**out;
	int			y;

	y = NEG;
	_NOTIS_FREE_ALL(out = (t_matrix**)malloc(sizeof(t_matrix*) * g_matrix_y));
	_NOTIS_FREE_ALL(g_matrix_x = add_numbers_inline(*file));
	while (++y < g_matrix_y)
	{
		_NOTIS_FREE_ALL(add_numbers_inline(file[y]) == g_matrix_x);
		_NOTIS_FREE_ALL(out[y] = (t_matrix*)malloc(sizeof(t_matrix) *
																(g_matrix_x)));
		_NOTIS_FREE_ALL(add_line_to_matrix(file[y], out[y]));
	}
	return (out);
}
