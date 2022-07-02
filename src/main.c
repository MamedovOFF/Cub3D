/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:31:23 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:56:06 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	ft_exit(t_cub *cub)
{
	clean_cub(cub);
	exit(0);
}

void	exit_with_error(char *message, t_cub *cub)
{
	ft_putendl_fd(message, STDOUT_FILENO);
	clean_cub(cub);
	exit(EXIT_FAILURE);
}

int	render(t_cub *cub)
{
	ft_bzero(cub->lib_mlx->data_addr, WIDTH * \
	HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
	ft_cast_rays(cub);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, \
	cub->lib_mlx->img, 0, 0);
	move(cub);
	return (0);
}

int	mouse_hook(int x, int y, t_cub *cub)
{
	(void)y;
	if (abs(x - cub->prev_x) > 10)
	{
		if (x - cub->prev_x > 0)
			cub->z = -1 * MOUSESPEED;
		else
			cub->z = MOUSESPEED;
		cub->key->mouse_left = 1;
	}
	else if (x == cub->prev_x)
		cub->key->mouse_right = 1;
	cub->prev_x = x;
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = parsing(argc, argv);
	cub->lib_mlx = init_lib_mlx(cub);
	if (NULL == cub->lib_mlx)
		exit_with_error(MALLOC_FAILURE, cub);
	set_images(cub);
	mlx_hook(cub->lib_mlx->mlx_win, 17, 0, ft_exit, cub);
	mlx_hook(cub->lib_mlx->mlx_win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->lib_mlx->mlx_win, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->lib_mlx->mlx_win, 6, 0, mouse_hook, cub);
	mlx_mouse_hide();
	mlx_loop_hook(cub->lib_mlx->mlx, &render, (void *) cub);
	mlx_loop(cub->lib_mlx->mlx);
	return (0);
}
