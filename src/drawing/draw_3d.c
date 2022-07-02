/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:20:11 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:35:07 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_tex_x(t_cub *cub, t_texture *texture)
{
	cub->dda->tex_x = (int)(cub->config->wall_x * (double)texture->width);
	if (cub->dda->side == 0 && cub->pers->dir_x < 0)
		cub->dda->tex_x = texture->width - cub->dda->tex_x - 1;
	if (cub->dda->side == 1 && cub->pers->dir_y > 0)
		cub->dda->tex_x = texture->width - cub->dda->tex_x - 1;
}

void	draw_wool(t_cub *cub, int x, t_texture *texture)
{
	int		r;
	int		g;
	int		b;
	double	step;
	double	pos;

	calc_tex_x(cub, texture);
	step = 1.0 * texture->height / cub->dda->line_height;
	pos = (cub->dda->draw_start - HEIGHT / 2 \
	+ cub->dda->line_height / 2) * step;
	while (cub->dda->draw_start++ < cub->dda->draw_end)
	{
		cub->dda->tex_y = (int)pos & (texture->height - 1);
		pos += step;
		b = (unsigned char)texture->data_addr[cub->dda->tex_y \
		* texture->line_length + cub->dda->tex_x * texture->bits_per_pixel / 8];
		g = (unsigned char)texture->data_addr[cub->dda->tex_y * \
		texture->line_length + cub->dda->tex_x \
		* texture->bits_per_pixel / 8 + 1];
		r = (unsigned char)texture->data_addr[cub->dda->tex_y \
		* texture->line_length + cub->dda->tex_x \
		* texture->bits_per_pixel / 8 + 2];
		put_pixel(x, cub->dda->draw_start, cub->lib_mlx, \
		create_rgb(r, g, b));
	}
}

void	draw_floors(t_cub *cub, int x)
{
	int	i;

	i = 0;
	if (cub->dda->draw_end < 0)
		cub->dda->draw_end = HEIGHT;
	i = cub->dda->draw_end + 1;
	while (i < HEIGHT)
	{
		put_pixel(x, i, cub->lib_mlx, cub->config->c);
		put_pixel(x, HEIGHT - i - 1, cub->lib_mlx, cub->config->f);
		i++;
	}
}

void	drawning(t_cub *cub, int x)
{
	cub->dda->line_height = (int)(HEIGHT / cub->dda->perp_wall_dist);
	cub->dda->draw_start = -cub->dda->line_height / 2 + HEIGHT / 2;
	cub->dda->draw_end = cub->dda->line_height / 2 + HEIGHT / 2;
	if (cub->dda->draw_start < 0)
		cub->dda->draw_start = 0;
	if (cub->dda->draw_end >= HEIGHT)
		cub->dda->draw_end = HEIGHT - 1;
	if (cub->dda->side == 0 && cub->dda->ray_dir_x > 0)
		draw_wool(cub, x, cub->config->so_texture);
	else if (cub->dda->side == 0 && cub->dda->ray_dir_x < 0)
		draw_wool(cub, x, cub->config->no_texture);
	else if (cub->dda->side == 1 && cub->dda->ray_dir_y > 0)
		draw_wool(cub, x, cub->config->ea_texture);
	else if (cub->dda->side == 1 && cub->dda->ray_dir_y < 0)
		draw_wool(cub, x, cub->config->we_texture);
	draw_floors(cub, x);
}

void	ft_cast_rays(t_cub *cub)
{
	int	x;

	x = 0;
	while (x++ < WIDTH)
	{
		init_t_add(cub, x);
		calc_ray(cub);
		hit(cub);
		side(cub);
		drawning(cub, x);
	}
}
