/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:23:36 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/30 15:20:01 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parsing.h"

char	*get_ret(char *in_str, t_parse *parse)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = 0;
	while (in_str[len] != '\n')
		len++;
	len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == ret)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	while (i < len)
	{
		ret[i] = in_str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*str_proc(char **in_str, t_parse *parsing)
{
	char	*res;
	char	*new_in_str;

	new_in_str = *in_str;
	if (ft_strchr(new_in_str, '\n'))
	{
		res = get_ret(new_in_str, parsing);
		if (!res)
			exit_with_error_parse(MALLOC_FAILURE, parsing);
		if (ft_strlen(res) == ft_strlen(new_in_str))
			*in_str = NULL;
		else
			*in_str = ft_strdup(ft_strchr(new_in_str, '\n') + 1);
		free(new_in_str);
	}
	else
	{			
		res = ft_strdup(*in_str);
		if (!res)
			exit_with_error_parse(MALLOC_FAILURE, parsing);
		free(*in_str);
		*in_str = NULL;
	}
	return (res);
}

void	read_buff(int fd, char **str, char *buf)
{
	int		ret;
	char	*temp;

	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		if (!*str)
		{
			*str = ft_strdup("");
		}
		buf[ret] = 0;
		temp = *str;
		*str = ft_strjoin(*str, buf);
		free(temp);
		if (!ft_strchr(*str, '\n'))
			ret = read(fd, buf, BUFFER_SIZE);
		else
			ret = 0;
	}
}

char	*get_next_line(int fd, t_parse *parsing)
{
	char		*buf;
	static char	*in_str;

	if (-1 == fd || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == buf)
		exit_with_error_parse(MALLOC_FAILURE, parsing);
	if (!in_str || !ft_strchr(in_str, '\n'))
		read_buff(fd, &in_str, buf);
	free(buf);
	if (NULL == in_str)
		return (NULL);
	if (in_str && !in_str[0])
	{
		free(in_str);
		in_str = NULL;
		return (NULL);
	}
	return (str_proc(&in_str, parsing));
}
