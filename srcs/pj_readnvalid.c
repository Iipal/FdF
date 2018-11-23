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

t_file			*pj_read(cstring file_name)
{
	t_file	*out;
	string	temp;
	size_t	i;
	int		fd;

	_NOTIS_N(out = (t_file*)malloc(sizeof(t_file)));
	_NOTIS_N(fd = open(file_name, O_RDONLY));
	_NOTIS_N(read(fd, NULL, ZERO) >= ZERO);
	out->lines = ZERO;
	while ((ft_gnl(fd, &temp) > ZERO) && ++(out->lines))
		ft_strdel(&temp);
	close(fd);
	_NOTIS_N(out->tab = (string*)malloc(sizeof(string) * out->lines));
	out->tab[out->lines] = NULL;
	_NOTIS_N((fd = open(file_name, O_RDONLY)) > ZERO);
	i = NEG;
	while ((ft_gnl(fd, &temp) > ZERO) && (out->tab[++i] = ft_strdup(temp)))
		ft_strdel(&temp);
	close(fd);
	return (out);
}

static size_t	add_numbers_counter(cstring line)
{
	size_t	n;
	size_t	i;
	bool	is;

	n = ZERO;
	i = NEG;
	while (line[++i])
	{
		if (ft_isalpha(line[i]) || (line[i] == ','))
			++i;
		else if (ft_isdigit(line[i]) && (!is ? is = true : !is))
			++n;
		(!ft_isdigit(line[i]) && is) ? is = false : is;
	}
	return (!n ? n : n + 1);
}

static t_matrix	*add_save_line(cstring line, const size_t numbers)
{
	t_matrix	*out;
	bool		is;
	size_t		start;
	size_t		x;
	int			i;

	x = ZERO;
	i = NEG;
	start = ZERO;
	_NOTIS_N(out = (t_matrix*)malloc(sizeof(t_matrix) * numbers));
	while ((++i >= 0) && x < numbers)
		if (ft_isdigit(line[i]) && (!is ? is = true : !is))
			start = i;
		else if (!ft_isdigit(line[i]) && is)
		{
			is = false;
			out[x].rgb = IRGB_WHITE;
			if (line[i] == ',')
			{
				out[x].rgb = ft_atoi_base(line + (i + 3), HEX);
				i += 9;
			}
			out[x++].z = ft_atoi(line + start);
		}
	return (out);
}

t_matrix		**pj_savenvalid(t_file *file)
{
	t_matrix	**out;
	size_t		i;
	size_t		numbers;

	_NOTIS_N(out = (t_matrix**)malloc(sizeof(t_matrix*) * file->lines));
	_NOTIS_N(numbers = add_numbers_counter(file->tab[ZERO]));
	out[file->lines] = NULL;
	i = NEG;
	while (++i < file->lines)
	{
		_NOTIS_N(add_numbers_counter(file->tab[i]) == numbers);
		_NOTIS_N(out[i] = add_save_line(file->tab[i], numbers));
	}
	g_matrix_y = file->lines;
	g_matrix_x = numbers;
	return (out);
}
