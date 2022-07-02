/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:42 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:32:43 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "get_next_line.h"

t_list	*read_info(char	*file_name, t_parse *parse)
{
	t_list	*list;
	char	*line;

	parse->fd = open(file_name, O_RDONLY);
	if (-1 == parse->fd)
	{
		perror("Error");
		exit_with_error_parse("FILE ERROR", parse);
	}
	parse->fd_opened = 1;
	line = NULL;
	list = NULL;
	line = get_next_line(parse->fd, parse);
	while (line)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
		line = get_next_line(parse->fd, parse);
	}
	close(parse->fd);
	parse->fd_opened = 0;
	return (list);
}

int	parse_config(t_parse *parse)
{
	while (parse->curent_data && 10 != parse->status)
	{
		parse->trimmed_str = ft_strtrim(parse->curent_data->content, " \n");
		if (parse->trimmed_str && parse->trimmed_str[0])
		{
			if (!parse->trimmed_str)
				exit_with_error_parse(MALLOC_FAILURE, parse);
			parse->splitted_str = ft_split(parse->trimmed_str, ' ');
			if (!parse->splitted_str)
				exit_with_error_parse(MALLOC_FAILURE, parse);
			if (2 != len_2d_str(parse->splitted_str))
				exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
			check_config(parse->splitted_str, parse);
			str_2d_clean(parse->splitted_str, len_2d_str(parse->splitted_str));
			parse->splitted_str = NULL;
		}
		free(parse->trimmed_str);
		parse->trimmed_str = NULL;
		parse->curent_data = parse->curent_data->next;
	}
	return (parse->status);
}

void	set_image(t_texture *texture, t_cub *cub)
{
	texture->img = mlx_xpm_file_to_image(cub->lib_mlx->mlx, texture->path,
			&texture->width, &texture->height);
	if (NULL == texture->img)
		exit_with_error("ERROR\nTexture file reading has failed", cub);
	texture->data_addr = mlx_get_data_addr(texture->img, \
		&texture->bits_per_pixel, \
		&texture->line_length, &texture->endian);
	if (NULL == texture->data_addr)
		exit_with_error("ERROR\nMLX get data addr failed", cub);
	ft_putendl_fd("Success : init ", 1);
}

void	set_images(t_cub *cub)
{
	set_image(cub->config->ea_texture, cub);
	set_image(cub->config->no_texture, cub);
	set_image(cub->config->so_texture, cub);
	set_image(cub->config->we_texture, cub);
}

t_cub	*parsing(int argc, char **argv)
{
	t_parse		*parse;
	t_cub		*cub;
	int			ret;

	valid_filename(argc, argv);
	parse = init_parse();
	parse->input_data = read_info(argv[1], parse);
	parse->curent_data = parse->input_data;
	ret = parse_config(parse);
	if (0 == ret && parse->config_count < 6)
		exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	if (10 == ret)
		ft_putendl_fd("SUCCESS : parse confingure - OK", 1);
	parse_map(parse);
	cub = parse->cub;
	clean_parse_inner(parse);
	free(parse);
	return (cub);
}
