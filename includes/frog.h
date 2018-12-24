/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipal <ipal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:23:16 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/24 10:24:21 by ipal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROG_H
# define FROG_H

# define FFILE_NAME	"test_maps/frog_bonus.fdf"

# define FBG_COLOR	197379

# define IRGB_GRAY		3355443
# define IRGB_WHITE		16777215
# define IRGB_LIME		8388352
# define IRGB_CHERRY	15865942
# define IRGB_AQUA		7273983
# define IRGB_PINK		13704642
# define IRGB_ORANGE	16758835
# define IRGB_PURPLE	3356415

# define FHEIGHT	19
# define FWIDTH		21

itab	fdf_bonus_init_frog(void);
void	fdf_print_fucking_frog(t_env *env);
void	fdf_is_render_frog(t_isrender *isr, t_env *env);

#endif
