/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:02:19 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:36:40 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(int x, int y, t_mlx *lib_mlx, int color)
{
	char	*dst;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = lib_mlx->data_addr + (y * lib_mlx->line_length \
		+ x * (lib_mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_t_add(t_cub *cub, int x)
{
	cub->dda->camera_x = 2 * x / (double)WIDTH - 1;
	cub->dda->ray_dir_x = cub->pers->dir_x + \
	cub->pers->plane_x * cub->dda->camera_x;
	cub->dda->ray_dir_y = cub->pers->dir_y + \
	cub->pers->plane_y * cub->dda->camera_x;
	cub->dda->map_x = (int)cub->pers->x;
	cub->dda->map_y = (int)cub->pers->y;
	cub->dda->delta_dist_x = fabs(1 / cub->dda->ray_dir_x);
	cub->dda->delta_dist_y = fabs(1 / cub->dda->ray_dir_y);
	cub->dda->hit = 0;
}

void	side(t_cub *cub)
{
	if (cub->dda->side == 0)
	{
		cub->dda->perp_wall_dist = (cub->dda->side_dist_x \
		- cub->dda->delta_dist_x);
		cub->config->wall_x = cub->pers->y + cub->dda->perp_wall_dist \
		* cub->dda->ray_dir_y;
	}
	else
	{
		cub->dda->perp_wall_dist = (cub->dda->side_dist_y \
		- cub->dda->delta_dist_y);
		cub->config->wall_x = cub->pers->x + cub->dda->perp_wall_dist \
		* cub->dda->ray_dir_x ;
	}
	cub->config->wall_x -= floor(cub->config->wall_x);
}

void	hit(t_cub *cub)
{
	while (cub->dda->hit == 0)
	{
		if (cub->dda->side_dist_x < cub->dda->side_dist_y)
		{
			cub->dda->side_dist_x += cub->dda->delta_dist_x;
			cub->dda->map_x += cub->dda->step_x;
			cub->dda->side = 0;
		}
		else
		{
			cub->dda->side_dist_y += cub->dda->delta_dist_y;
			cub->dda->map_y += cub->dda->step_y;
			cub->dda->side = 1;
		}
		if (cub->map[cub->dda->map_x][cub->dda->map_y] != '0')
			cub->dda->hit = 1;
	}
}

void	calc_ray(t_cub *cub)
{
	if (cub->dda->ray_dir_x < 0)
	{
		cub->dda->step_x = -1;
		cub->dda->side_dist_x = (cub->pers->x - cub->dda->map_x) \
		* cub->dda->delta_dist_x;
	}
	else
	{
		cub->dda->step_x = 1;
		cub->dda->side_dist_x = (cub->dda->map_x + 1.0 - cub->pers->x) \
		* cub->dda->delta_dist_x;
	}
	if (cub->dda->ray_dir_y < 0)
	{
		cub->dda->step_y = -1;
		cub->dda->side_dist_y = (cub->pers->y - cub->dda->map_y) \
		* cub->dda->delta_dist_y;
	}
	else
	{
		cub->dda->step_y = 1;
		cub->dda->side_dist_y = (cub->dda->map_y + 1.0 - cub->pers->y) \
		* cub->dda->delta_dist_y;
	}
}
