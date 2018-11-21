/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:51:14 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/20 16:51:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_file		*f_read(cstring file_name)
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
	_NOTIS_N(out->tab = (cstring*)malloc(sizeof(cstring) * out->lines));
	out->tab[out->lines] = NULL;
	_NOTIS_N((fd = open(file_name, O_RDONLY)) > ZERO);
	i = NEG;
	while ((ft_gnl(fd, &temp) > ZERO) && (out->tab[++i] = ft_strdup(temp)))
		ft_strdel(&temp);
	close(fd);
	return (out);
}

static size_t	number_counter(cstring line)
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
	return (n);
}

t_matrix	**f_savenvalid(t_file *file)
{
	t_matrix	**out;
	size_t		i;
	size_t		n;

	_NOTIS_N(out = (t_matrix**)malloc(sizeof(t_matrix*) * file->lines));
	i = NEG;
	_NOTIS_N(n = number_counter(file->tab[++i]));
	out[file->lines] = NULL;
	while (++i < file->lines)
		if (number_counter(file->tab[i]) != n)
			return (NULL);
	while (++i < file->lines)
		_NOTIS_N(out[i] = (t_matrix*)malloc(sizeof(t_matrix) * n));
	i = NEG;
	while (++i < file->lines)
	{
		
	}
	return (out);
}
