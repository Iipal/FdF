/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_readnvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:46:48 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/23 13:47:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

string			*pj_fileread(cstring file_name)
{
	string	*out_tab;
	string	gnl_temp;
	size_t	i;
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
	_NOTIS_N(out_tab = (string*)malloc(sizeof(string) * (g_matrix_y - POS)));
	_NOTIS_N(fd = open(file_name, O_RDONLY));
	i = ZERO;
	while (ft_gnl(fd, &gnl_temp) > ZERO)
	{
		out_tab[i++] = ft_strdup(gnl_temp);
		ft_strdel(&gnl_temp);
	}
	return (out_tab);
}

static size_t	add_numbers_inline(string line)
{
	size_t	out_numbers_counter;
	size_t	number_abs_temp;
	size_t	digits;
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
			line += digits;
			++out_numbers_counter;
		}
		if (*line == ',')
			line += 9;
		++line;
	}
	return (out_numbers_counter);
}

static bool		add_line_to_matrix(string line, t_matrix *matrix)
{
	size_t		x;
	size_t		digits;
	size_t		number_abs_temp;

	x = ZERO;
	while (*line && x < g_matrix_x)
	{
		if (ft_isdigit(*line) || *line == '-')
		{
			digits = ZERO;
			matrix[x].rgb = IRGB_WHITE;
			matrix[x].z = ft_atoi(line);
			number_abs_temp = _ABS(matrix[x].z);
			_DIGITS_IN_NUMBER(number_abs_temp);
			line += digits;
			if (*line == ',')
			{
				_NOTIS_F(matrix[x].rgb = ft_atoi_base(line + 3, HEX));
				line += 9;
			}
			++x;
		}
		++line;
	}
	return (true);
}

t_matrix		**pj_savenvalid(string *file)
{
	t_matrix	**out;
	size_t		i;

	_NOTIS_N(out = (t_matrix**)malloc(sizeof(t_matrix*)));
	_NOTIS_N(g_matrix_x = add_numbers_inline(*file));
	i = ZERO;
	while (i < g_matrix_y)
	{
		_NOTIS_N(add_numbers_inline(file[i]) == g_matrix_x);
		_NOTIS_N(out[i] = (t_matrix*)malloc(sizeof(t_matrix) * (g_matrix_x)));
		_NOTIS_N(add_line_to_matrix(file[i], out[i]));
		++i;
	}
	return (out);
}
