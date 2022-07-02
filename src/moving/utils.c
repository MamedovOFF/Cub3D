/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:26:45 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 20:09:22 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_w(t_cub *cub)
{
	if (cub->map[(int)(cub->pers->x + cub->pers->dir_x * sin(MOVESPEED))] \
	[(int)cub->pers->y] == '0')
		cub->pers->x += cub->pers->dir_x * sin(MOVESPEED);
	if (cub->map[(int)cub->pers->x] \
	[(int)(cub->pers->y + cub->pers->dir_y * sin(MOVESPEED))] == '0')
		cub->pers->y += cub->pers->dir_y * sin(MOVESPEED);
}

void	move_s(t_cub *cub)
{
	if (cub->map[(int)(cub->pers->x - cub->pers->dir_x * sin(MOVESPEED))] \
	[(int)cub->pers->y] == '0')
		cub->pers->x -= cub->pers->dir_x * sin(MOVESPEED);
	if (cub->map[(int)cub->pers->x] \
	[(int)(cub->pers->y - cub->pers->dir_y * sin(MOVESPEED))] == '0')
		cub->pers->y -= cub->pers->dir_y * sin(MOVESPEED);
}

void	move_a(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->pers->dir_x;
	old_plane_x = cub->pers->plane_x;
	cub->pers->dir_x = cub->pers->dir_x * cos(-ROTATESPEED) \
	- cub->pers->dir_y * sin(-ROTATESPEED);
	cub->pers->dir_y = old_dir_x * sin(-ROTATESPEED) \
	+ cub->pers->dir_y * cos(-ROTATESPEED);
	cub->pers->plane_x = cub->pers->plane_x * cos(-ROTATESPEED) \
	- cub->pers->plane_y * sin(-ROTATESPEED);
	cub->pers->plane_y = old_plane_x * sin(-ROTATESPEED) \
	+ cub->pers->plane_y * cos(-ROTATESPEED);
}

void	move_d(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->pers->dir_x;
	old_plane_x = cub->pers->plane_x;
	cub->pers->dir_x = cub->pers->dir_x * cos(ROTATESPEED) \
	- cub->pers->dir_y * sin(ROTATESPEED);
	cub->pers->dir_y = old_dir_x * sin(ROTATESPEED) \
	+ cub->pers->dir_y * cos(ROTATESPEED);
	cub->pers->plane_x = cub->pers->plane_x * cos(ROTATESPEED) \
	- cub->pers->plane_y * sin(ROTATESPEED);
	cub->pers->plane_y = old_plane_x * sin(ROTATESPEED) \
	+ cub->pers->plane_y * cos(ROTATESPEED);
}

void	move_mouse(t_cub *cub, double z)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->pers->dir_x;
	old_plane_x = cub->pers->plane_x;
	cub->pers->dir_x = cub->pers->dir_x * cos(z) \
	- cub->pers->dir_y * sin(z);
	cub->pers->dir_y = old_dir_x * sin(z) \
	+ cub->pers->dir_y * cos(z);
	cub->pers->plane_x = cub->pers->plane_x * cos(z) \
	- cub->pers->plane_y * sin(z);
	cub->pers->plane_y = old_plane_x * sin(z) \
	+ cub->pers->plane_y * cos(z);
}
