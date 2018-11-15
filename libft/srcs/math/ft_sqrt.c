/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:15:02 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/27 19:15:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_math.h"

int		ft_sqrt(int nb)
{
	int sol;

	if (nb <= 0)
		return (0);
	sol = 1;
	while (sol * sol < nb)
		sol++;
	if (sol * sol == nb)
		return (sol);
	else
		return (0);
}
