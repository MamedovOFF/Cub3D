/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:30 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:32:31 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	default_init_parse(t_parse *parse)
{
	parse->input_data = NULL;
	parse->trimmed_str = NULL;
	parse->splitted_str = NULL;
	parse->config_names = NULL;
	parse->cub = NULL;
}

t_parse	*init_parse(void)
{
	t_parse	*parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	if (NULL == parse)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	default_init_parse(parse);
	parse->cub = init_cub(parse);
	parse->config_names = ft_split("NO SO WE EA F C", ' ');
	if (NULL == parse->config_names)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	set_config_funcs(parse);
	parse->config_count = 0;
	parse->status = 2;
	parse->fd_opened = 0;
	return (parse);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	init_color(char *rgb, t_parse *parse, int	*color)
{
	int		*colors;
	char	**splitted;

	splitted = ft_split(rgb, ',');
	if (NULL == splitted)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	colors = (int *)malloc(sizeof(int) * 3);
	if (NULL == colors)
	{
		str_2d_clean(splitted, len_2d_str(splitted));
		exit_with_error_parse(MALLOC_FAILURE, parse);
	}
	colors[0] = parse_int(splitted[0]);
	colors[1] = parse_int(splitted[1]);
	colors[2] = parse_int(splitted[2]);
	if (-1 == colors[0] || -1 == colors[1] || -1 == colors[2])
	{
		free(colors);
		exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	}
	*color = create_rgb(colors[0], colors[1], colors[2]);
	str_2d_clean(splitted, len_2d_str(splitted));
	free(colors);
}
