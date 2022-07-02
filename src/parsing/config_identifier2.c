/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_identifier2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:25 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:32:26 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_ea(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init EA", 1);
	open_texture(path, parse, &parse->cub->config->ea_texture);
}

void	init_f(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init F", 1);
	init_color(path, parse, &parse->cub->config->f);
}

void	init_c(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init C", 1);
	init_color(path, parse, &parse->cub->config->c);
}

void	set_config_funcs(t_parse *parse)
{
	parse->config_init[0] = init_no;
	parse->config_init[1] = init_so;
	parse->config_init[2] = init_we;
	parse->config_init[3] = init_ea;
	parse->config_init[4] = init_f;
	parse->config_init[5] = init_c;
}
