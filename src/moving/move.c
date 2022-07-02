/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:21:27 by spurple           #+#    #+#             */
/*   Updated: 2022/06/28 19:46:57 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == 13)
		cub->key->w = 1;
	if (keycode == 1)
		cub->key->s = 1;
	if (keycode == 0 || keycode == 123)
		cub->key->d = 1;
	if (keycode == 2 || keycode == 124)
		cub->key->a = 1;
	if (keycode == 53)
		ft_exit(cub);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == 13)
		cub->key->w = 0;
	if (keycode == 1)
		cub->key->s = 0;
	if (keycode == 0 || keycode == 123)
		cub->key->d = 0;
	if (keycode == 2 || keycode == 124)
		cub->key->a = 0;
	return (0);
}

void	move(t_cub *cub)
{
	if (cub->key->w == 1)
		move_w(cub);
	if (cub->key->s == 1)
		move_s(cub);
	if (cub->key->a == 1)
		move_a(cub);
	if (cub->key->d == 1)
		move_d(cub);
	if (cub->key->mouse_left == 1)
	{
		move_mouse(cub, cub->z);
		cub->prev_z = cub->z;
		cub->key->mouse_left = 0;
	}
	if (cub->key->mouse_right == 1)
	{
		move_mouse(cub, cub->prev_z);
		cub->key->mouse_right = 0;
	}
}
