/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:28 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:33:13 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_flags(t_key *key)
{
	key->a = 0;
	key->d = 0;
	key->w = 0;
	key->s = 0;
	key->mouse_left = 0;
	key->mouse_right = 0;
}

t_mlx	*init_lib_mlx(t_cub *cub)
{
	t_mlx	*lib_mlx;

	lib_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (NULL == lib_mlx)
		exit_with_error(MALLOC_FAILURE, cub);
	lib_mlx->mlx = mlx_init();
	lib_mlx->mlx_win = mlx_new_window(lib_mlx->mlx, WIDTH, HEIGHT, "CUB3D");
	lib_mlx->img = mlx_new_image(lib_mlx->mlx, WIDTH, HEIGHT);
	lib_mlx->data_addr = mlx_get_data_addr(lib_mlx->img, \
		&(lib_mlx->bits_per_pixel), \
				&(lib_mlx->line_length), &(lib_mlx->endian));
	return (lib_mlx);
}

void	default_init_cub(t_cub *cub)
{
	cub->dda = NULL;
	cub->map = NULL;
	cub->pers = NULL;
	cub->lib_mlx = NULL;
	cub->config = NULL;
	cub->key = NULL;
	cub->x = 0;
}

void	init_config(t_config *conf)
{
	conf->no_texture = NULL;
	conf->so_texture = NULL;
	conf->we_texture = NULL;
	conf->ea_texture = NULL;
	conf->f = 0;
	conf->c = 0;
}

t_cub	*init_cub(t_parse *parse)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (NULL == cub)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	default_init_cub(cub);
	cub->config = (t_config *)malloc(sizeof(t_config));
	if (NULL == cub->config)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	init_config(cub->config);
	cub->key = (t_key *)malloc(sizeof(t_key));
	if (NULL == cub->key)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	init_flags(cub->key);
	cub->pers = (t_pers_pos *) malloc(sizeof(t_pers_pos));
	if (NULL == cub->pers)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	cub->dda = (t_dda *)malloc(sizeof(t_dda));
	if (NULL == cub->dda)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	cub->pers->side = 0;
	return (cub);
}
