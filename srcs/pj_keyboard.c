/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:00:49 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/05 15:54:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/mac_keycodes.h"
#include "../includes/additional_structs.h"

static int	add_close_window(int key, t_mnm *mnm)
{
	if (key == ESC)
	{
		mlx_destroy_window(mnm->mlx->mlx, mnm->mlx->win);
		pj_mnm_free(mnm);
	}
	if (key == NUMPAD_PLUS || key == KEYBOARD_PLUS)
	{
		mlx_clear_window(mnm->mlx->mlx, mnm->mlx->win);
		pj_matrix_upscale(mnm->m, DEC);
	}
	return (true);
}

void		pj_key_pressed(t_mlx *mlx, t_matrix **matrix)
{
	t_mnm	*mnm;

	mnm = (t_mnm*)malloc(sizeof(t_mnm));
	mnm->mlx = mlx;
	mnm->m = matrix;
	mlx_key_hook(mlx->win, add_close_window, mnm);
}
