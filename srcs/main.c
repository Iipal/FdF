/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:47:35 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 18:10:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char const *argv[])
{
	t_env	*env;

	--argc;
	++argv;
	env = NULL;
	_NOTIS_MSG("Usage: ./fdf <map_name>", !(!argc || argc > 1));
	_NOTIS_MPE("", env = fdf_file_readnsave_tomatrix_env(*argv));
	mlx_loop(env->mlx);
}
