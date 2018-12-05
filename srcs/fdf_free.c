/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:10:47 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 18:45:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	File with all "free" functions.
**		'fdf_file_free' - Free "file". About "file":
**			| - Created in 'fdf_file_readnsave_tomatrix_env'. (fdf_readnsave.c)
**			| - Including in 'add_save_tomatrix'. (fdf_readnsave.c)
*/

void	fdf_file_free(string *file, int lines)
{
	int	i;

	i = NEG;
	while (++i < lines)
		ft_strdel(&(file[i]));
	free(file);
	file = NULL;
}
