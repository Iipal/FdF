/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:11:40 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:26:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_ctype.h"

static inline int	ft_check_spaces(cstring str)
{
	int		i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) ||
			(str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r'))
		i++;
	return (i);
}

static inline void	ft_check_sign(cstring str, int *i, int *sign)
{
	if (str[*i] == '-')
		*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

int					ft_atoi(cstring str)
{
	int		i;
	int		num;
	int		sign;

	sign = 0;
	i = ft_check_spaces(str);
	num = 0;
	ft_check_sign(str, &i, &sign);
	while (ft_isdigit(str[i]))
	{
		if (9223372036854775807 - num < str[i] - 48)
		{
			if (sign)
				return (0);
			else
				return (-1);
		}
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (sign)
		num = -num;
	return (num);
}
