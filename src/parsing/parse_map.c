/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:36 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:32:37 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_borders(char *str, t_parse *parse)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '1')
	{
		if ('0' == str[i])
			exit_with_error_parse(MAP_FAILURE, parse);
	}
	if (i == (int) ft_strlen(str))
		exit_with_error_parse(MAP_FAILURE, parse);
	i = (int) ft_strlen(str);
	while (--i >= 0 && str[i] != '1')
	{
		if ('0' == str[i])
			exit_with_error_parse(MAP_FAILURE, parse);
	}
	if (i == -1)
		exit_with_error_parse(MAP_FAILURE, parse);
	return (0);
}

void	check_top_bottom(char **map, t_parse *parse)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	while (map[0][++j])
	{
		if (map[0][j] == '0')
			exit_with_error_parse(MAP_FAILURE, parse);
	}
	len = len_2d_str(map);
	j = -1;
	while (map[len - 1][++j])
	{
		if (map[len - 1][j] == '0')
			exit_with_error_parse(MAP_FAILURE, parse);
	}
	while (map[++i])
		check_borders(map[i], parse);
}

char	**list_to2darr(t_list *list, t_parse *parse)
{
	int		size;
	char	**arr;
	int		i;

	while (list && ((char *) list->content)[0] == '\n')
		list = list->next;
	if (NULL == list)
		exit_with_error_parse(MAP_FAILURE, parse);
	size = ft_lstsize(list);
	parse->cub->map_len = size;
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (NULL == arr)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	i = -1;
	while (++i < size)
	{
		arr[i] = ft_strtrim(list->content, "\n");
		if (NULL == arr[i])
			exit_with_error_parse(MALLOC_FAILURE, parse);
		list = list->next;
	}
	arr[i] = NULL;
	return (arr);
}

void	firstly_parse(char **map, t_parse *parse)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			proc_symbol(map, i, j, parse);
		}
	}
	if (0 == parse->cub->pers->side)
		exit_with_error_parse(NUMBER_CHAR_FAILURE, parse);
}

int	parse_map(t_parse *parse)
{
	parse->cub->map = list_to2darr(parse->curent_data, parse);
	check_top_bottom(parse->cub->map, parse);
	firstly_parse(parse->cub->map, parse);
	ft_putendl_fd("MAP OK", 1);
	return (1);
}
