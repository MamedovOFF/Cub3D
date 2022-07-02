/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:32:44 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 19:32:45 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_strcmp( const char *str1, const char *str2 )
{
	while ((*str1) && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	if (*(unsigned char *)str1 > *(unsigned char *)str2)
		return (1);
	else if (*(unsigned char *)str1 < *(unsigned char *) str2)
		return (-1);
	else
		return (0);
}

int	check_config(char **config, struct s_parse *parse)
{
	int	i;

	i = 0;
	while (parse->config_names[i])
	{
		if (!ft_strcmp(parse->config_names[i], config[0]))
		{
			(*parse->config_init[i])(config[1], parse);
			if (6 == parse->config_count)
				parse->status = 10;
			return (2);
		}
		i++;
	}
	exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	return (0);
}

int	ends_with(char *input, char *postfix)
{
	int		ok;
	char	*end;

	if (ft_strlen(input) - ft_strlen(postfix) < 1)
		return (0);
	end = ft_substr(input, ft_strlen(input) - 4, ft_strlen(input));
	if (NULL == end)
	{
		ft_putendl_fd(MALLOC_FAILURE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ok = 1;
	if (ft_strcmp(end, postfix))
		ok = 0;
	free(end);
	return (ok);
}

void	valid_filename(int argc, char **argv)
{
	if (2 != argc)
	{
		ft_putendl_fd(NUMBER_ARGS_FAILURE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ends_with(argv[1], FILE_TYPE))
	{
		ft_putendl_fd(FILE_FORMAT_FAILURE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd("SUCCESS : File format ok", 1);
}

int	parse_int(char *str)
{
	int	a;
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strlen(str) > 3)
			return (-1);
		if (!ft_isdigit(str[i]))
			return (-1);
	}
	a = ft_atoi(str);
	if (a > 255)
		return (-1);
	return (a);
}
