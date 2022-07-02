/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:03 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:32:04 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "get_next_line.h"

void	open_texture(char *path, t_parse *parse, t_texture **texture1)
{
	int			fd;
	t_texture	*texture;

	texture = (t_texture *) malloc(sizeof(t_texture));
	if (NULL == texture)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	texture->path = NULL;
	texture->img = NULL;
	if (!ends_with(path, TEXTURE_FORMAT))
	{
		exit_with_error_parse(TEXTURE_FORMAT_FAILURE, parse);
	}
	fd = open(path, O_RDONLY);
	if (-1 == fd)
	{
		exit_with_error_parse(strerror(errno), parse);
	}
	close(fd);
	texture->path = ft_strdup(path);
	*texture1 = texture;
}

int	check_i(int i, t_parse *parse)
{
	if (0 == i)
		parse->config_count++;
	if (i == 1)
		exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	i = 1;
	return (0);
}

void	init_no(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init NO", 1);
	open_texture(path, parse, &parse->cub->config->no_texture);
}

void	init_so(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init SO", 1);
	open_texture(path, parse, &parse->cub->config->so_texture);
}

void	init_we(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init WE", 1);
	open_texture(path, parse, &parse->cub->config->we_texture);
}
