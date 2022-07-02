/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:32:01 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/18 16:35:09 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(const char *s, size_t len, int start, size_t add_len)
{
	char		*str;
	size_t		i;

	i = 0;
	if (add_len <= len)
		str = (char *) malloc ((add_len + 1) * sizeof(char));
	else
		str = (char *) malloc ((len + 1) * sizeof(char));
	if ((void *)0 == str)
		return ((void *) 0);
	while (i < add_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	add_len;
	char	*sub_s;
	size_t	str_len;

	if (!s)
		return ((void *) 0);
	i = 0;
	str_len = ft_strlen(s);
	if (str_len <= start)
	{
		sub_s = ft_calloc(1, sizeof(char));
		if ((void *)0 == sub_s)
			return ((void *) 0);
		return (sub_s);
	}
	add_len = str_len - start;
	if (len < add_len)
		add_len = len;
	sub_s = (char *)fill_str(s, len, start, add_len);
	if ((void *)0 == sub_s)
		return ((void *) 0);
	return (sub_s);
}
