/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:30:32 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 15:12:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

void	ft_striter(string s, void (*f)(string))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = -1;
	if (s)
		while (s[++i])
			f(&s[i]);
}
