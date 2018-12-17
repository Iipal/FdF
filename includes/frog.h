/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:23:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/17 22:12:54 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROG_H
# define FROG_H

# define FFILE_NAME	"test_maps/frog_bonus.fdf"

# define FHEIGHT	19
# define FWIDTH		21

int		**bonus_init_frog(void);
void	add_print_fucking_frog(t_env *env);
void	add_is_render_bonus(t_isrender *isr, t_env *env);

#endif
