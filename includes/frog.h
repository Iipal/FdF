/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:23:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/20 09:49:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROG_H
# define FROG_H

# define FFILE_NAME	"test_maps/frog_bonus.fdf"

# define FBG_COLOR	197379

# define FHEIGHT	19
# define FWIDTH		21

itab	fdf_bonus_init_frog(void);
void	fdf_print_fucking_frog(t_env *env);
void	fdf_is_render_frog(t_isrender *isr, t_env *env);

#endif
