/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:20:53 by spurple           #+#    #+#             */
/*   Updated: 2022/06/28 21:40:34 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	len_2d_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	str_2d_clean(char **s, size_t l)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < l)
		{
			free (s[i]);
			i++;
		}
		free (s);
	}
}

void	clean_texture(t_texture *texture, t_cub *cub)
{
	(void) cub;
	if (texture)
	{
		if (texture->path)
			free(texture->path);
		if (texture->img)
			mlx_destroy_image(cub->lib_mlx->mlx, texture->img);
		free(texture);
	}
}

void	clean_config(t_config *conf, t_cub *cub)
{
	if (conf)
	{
		clean_texture(conf->no_texture, cub);
		clean_texture(conf->we_texture, cub);
		clean_texture(conf->so_texture, cub);
		clean_texture(conf->ea_texture, cub);
		free(conf);
	}
}

void	clean_cub(t_cub *cub)
{
	if (cub->map)
		str_2d_clean(cub->map, len_2d_str(cub->map));
	if (cub->pers)
		free(cub->pers);
	clean_config(cub->config, cub);
	if (cub->lib_mlx)
	{
		if (cub->lib_mlx->mlx && cub->lib_mlx->mlx_win)
		{
			mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
		}
		free(cub->lib_mlx);
	}
	if (cub->dda)
		free(cub->dda);
	if (cub->key)
		free(cub->key);
	free(cub);
}
