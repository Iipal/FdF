/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_additional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:10:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/10 18:11:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/frog.h"

void	fdf_add_print_usage(void)
{
	_MSGN("\t[W | A | S | D] or Arrows for moving.");
	_MSGN("\t[+] & [-] on [numpad | keyboard] for zooming.");
	_MSGN("\t[I | P] - projections switch.");
	_MSGN("\t\t[I] - Isometric.");
	_MSGN("\t\t[P] - Perspective.");
	_MSGN("\t[ESC] - exit.");
	_MSGN("\t[C] - bonus.");
}
