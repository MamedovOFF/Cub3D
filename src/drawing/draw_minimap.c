/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:17:58 by spurple           #+#    #+#             */
/*   Updated: 2022/06/28 21:35:15 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square2(t_cub *cub, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < SCALE)
	{
		j = 0;
		while (j++ < SCALE)
			put_pixel(x + i, y + j, cub->lib_mlx, color);
	}
}

void	draw_square(t_cub *cub, int x, int y, char ch)
{
	int	color;

	if ((int)cub->pers->x == x && (int)cub->pers->y == y)
		color = create_rgb(0, 0, 255);
	else if ('1' == ch)
		color = create_rgb(255, 0, 0);
	else if ('0' == ch)
		color = create_rgb(105, 105, 105);
	else
		return ;
	draw_square2(cub, y * SCALE, x * SCALE, color);
}

void	draw_minimap(t_cub *cub)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = cub->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			draw_square(cub, i, j, map[i][j]);
			j++;
		}
		i++;
	}
}
