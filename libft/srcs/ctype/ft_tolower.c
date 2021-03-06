/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:21:52 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:35:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_ctype.h"

int		ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? c += 32 : c);
}
