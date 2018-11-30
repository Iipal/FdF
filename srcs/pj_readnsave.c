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
	_NOTIS_N(out_tab = (string*)malloc(sizeof(string) * g_matrix_y));
	_NOTIS_N(fd = open(file_name, O_RDONLY));
	i = ZERO;
	while (ft_gnl(fd, &gnl_temp) > ZERO)
	{
		out_tab[i++] = ft_strdup(gnl_temp);
		ft_strdel(&gnl_temp);
	}
	return (out_tab);
}

/*
**	'add_numbers_inline' additional function for 'pj_savenvalid'.
**			Used for known how much numbers in 1 'line' of "file".
*/

static int		add_numbers_inline(string line)
{
	int		out_numbers_counter;
	int		digits;

	out_numbers_counter = ZERO;
	while (*line)
	{
		if (ft_isdigit(*line) || *line == '-')
		{
			digits = ft_strlen(ft_itoa(ft_atoi(line)));
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

static bool		add_line_to_matrix(string line, t_matrix *matrix, int y)
{
	int			x;
	int			digits;

	x = ZERO;
	while (*line && x < g_matrix_x)
	{
		if ((ft_isdigit(*line) || *line == '-') && !(digits = ZERO))
		{
			matrix[x].y = y;
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

t_matrix		**pj_matrix_save(string *file)
{
	t_matrix	**out;
	int			y;

	y = NEG;
	_NOTIS_N(out = (t_matrix**)malloc(sizeof(t_matrix*) * g_matrix_y));
	_NOTIS_N(g_matrix_x = add_numbers_inline(*file));
	while (++y < g_matrix_y)
	{
		_NOTIS_N(add_numbers_inline(file[y]) == g_matrix_x);
		_NOTIS_N(out[y] = (t_matrix*)malloc(sizeof(t_matrix) * (g_matrix_x)));
		_NOTIS_N(add_line_to_matrix(file[y], out[y], y));
	}
	return (out);
}
