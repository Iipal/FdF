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

static bool	valid_file(t_file *file)
{
	if (file)
		;
	return (true);
}

t_file		*readnvalid(cstring file_name)
{
	t_file	*out;
	string	temp;
	size_t	i;
	int		fd;

	_NOTIS_N(out = (t_file*)malloc(sizeof(t_file)));
	_NOTIS_N(fd = open(file_name, O_RDONLY));
	_NOTIS_N(read(fd, NULL, 0) >= 0);
	out->lines = 0;
	while ((ft_gnl(fd, &temp) > 0) && ++(out->lines))
		ft_strdel(&temp);
	close(fd);
	_NOTIS_N(out->tab = (string*)malloc(sizeof(string) * out->lines));
	out->tab[out->lines] = NULL;
	_NOTIS_N((fd = open(file_name, O_RDONLY)) > 0);
	i = -1;
	while ((ft_gnl(fd, &temp) > 0) && (out->tab[++i] = ft_strdup(temp)))
		ft_strdel(&temp);
	close(fd);
	_NOTIS_N(valid_file(out));
	return (out);
}
