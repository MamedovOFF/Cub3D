/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:11:01 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/11 17:18:54 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	size;
	size_t	ok;

	size = 0;
	ok = 0;
	while (*str)
	{
		if (*str == c)
			ok = 0;
		else if (ok == 0)
		{
			ok = 1;
			size++;
		}
		str++;
	}
	return (size);
}

static char	*alloc(char const *str, char c, size_t	j)
{
	char		*word;
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	while (str[j + len] != c && str[j + len])
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if ((void *)0 == word)
		return ((void *)0);
	while (i < len)
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static void	memclean(char **s, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		free (s[i]);
		i++;
	}
	free (s);
}

static char	**split_work(char const*s, char **res, char c, char ok)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c)
			ok = 0;
		else if (ok == 0)
		{
			ok = 1;
			res[i] = alloc(s, c, j);
			if ((void *)0 == res[i])
			{
				memclean (res, i);
				return ((void *)0);
			}
			j += ft_strlen (res[i]) - 1;
			i++;
		}
		j++;
	}
	res[i] = (void *) 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	ok;
	char	**res;

	ok = 0;
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if ((void *)0 == res)
		return ((void *)0);
	if ((void *)0 == split_work(s, res, c, ok))
		return ((void *)0);
	return (res);
}
