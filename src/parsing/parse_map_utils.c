/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:33 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:38:27 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	init_perse2(t_parse *parse, char ch)
{
	if ('W' == ch)
	{
		parse->cub->pers->side = 'W';
		parse->cub->pers->dir_x = 0.0;
		parse->cub->pers->dir_y = -1.0;
		parse->cub->pers->plane_x = -0.66;
		parse->cub->pers->plane_y = 0.0;
	}
	else if ('E' == ch)
	{
		parse->cub->pers->side = 'E';
		parse->cub->pers->dir_x = 0.0;
		parse->cub->pers->dir_y = 1.0;
		parse->cub->pers->plane_x = 0.66;
		parse->cub->pers->plane_y = 0.0;
	}
	else if ('S' == ch)
	{
		parse->cub->pers->side = 'S';
		parse->cub->pers->dir_x = 1.0;
		parse->cub->pers->dir_y = 0.0;
		parse->cub->pers->plane_x = 0.0;
		parse->cub->pers->plane_y = -0.66;
	}
}

static void	init_perse(char ch, int i, int j, t_parse *parse)
{
	static int	flag = 0;

	if (1 == flag)
		exit_with_error_parse(NUMBER_CHAR_FAILURE, parse);
	flag = 1;
	if ('N' == ch)
	{
		parse->cub->pers->side = 'N';
		parse->cub->pers->dir_x = -1.0;
		parse->cub->pers->dir_y = 0.0;
		parse->cub->pers->plane_x = 0.0;
		parse->cub->pers->plane_y = 0.66;
	}
	else
		init_perse2(parse, ch);
	parse->cub->pers->x = i + 0.5;
	parse->cub->pers->y = j + 0.5;
}

int	is_pers(char ch)
{
	if ('N' == ch || 'W' == ch || 'E' == ch || 'S' == ch)
		return (1);
	return (0);
}

int	check_zerro_sym(char **map, int i, int j)
{
	if (i != 0)
	{
		if (((int) ft_strlen(map[i - 1]) - 2 < j))
			return (0);
		if ((map[i - 1][j] == ' ') || (j != 0 && map[i - 1][j - 1] == ' '))
			return (0);
	}
	if (i != len_2d_str(map) - 1)
	{
		if (((int) ft_strlen(map[i + 1]) - 2 < j))
			return (0);
		if ((map[i + 1][j] == ' ') || (map[i + 1][j - 1] == ' '))
			return (0);
	}
	if (j != 0 && (map[i][j - 1] == ' '))
		return (0);
	if (j != (int) ft_strlen(map[i]) - 1 && (map[i][j + 1] == ' '))
		return (0);
	return (1);
}

void	proc_symbol(char **map, int i, int j, t_parse *parse)
{
	char	ch;

	ch = map[i][j];
	if (is_pers(ch))
	{
		printf("PERS X %d\n", i);
		init_perse(ch, i, j, parse);
		map[i][j] = '0';
	}
	else if ('0' == ch && (0 == check_zerro_sym(map, i, j)))
		exit_with_error_parse(MAP_FAILURE, parse);
	else if ('1' != ch && ' ' != ch && '0' != ch)
	{
		printf("I == %d, J == %d, CH == %c", i, j, map[i][j]);
		exit_with_error_parse(ALLOWED_SYMB_FAILURE, parse);
	}
}
