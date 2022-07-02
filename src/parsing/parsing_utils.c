/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:40 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:32:41 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	clean_list(t_list *list)
{
	t_list	*temp_list;

	while (list)
	{
		temp_list = list->next;
		free(list->content);
		free (list);
		list = temp_list;
	}
}

void	clean_parse_inner(t_parse *parse)
{
	if (parse->fd_opened)
	{
		close(parse->fd);
	}
	if (parse->trimmed_str)
	{
		free(parse->trimmed_str);
	}
	if (parse->splitted_str)
	{
		str_2d_clean(parse->splitted_str, len_2d_str(parse->splitted_str));
	}
	clean_list(parse->input_data);
	str_2d_clean(parse->config_names, len_2d_str(parse->config_names));
}

void	exit_with_error_parse(char *error, t_parse *parse)
{
	if (parse)
	{
		clean_parse_inner(parse);
		clean_cub(parse->cub);
		free(parse);
	}
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
