/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:29:18 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/15 15:31:41 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char ch, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ch == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new_s;

	if (!s1 || !set)
		return ((void *)0);
	i = 0;
	k = 0;
	j = ft_strlen(s1);
	while (s1[i] && check(s1[i], set))
		i++;
	while (check(s1[j - 1], set) && j > i)
		j--;
	new_s = (char *)malloc((j - i + 1) * sizeof(char));
	if (!new_s)
		return ((void *)0);
	while (k < j - i)
	{
		new_s[k] = s1[i + k];
		k++;
	}
	new_s[k] = 0;
	return (new_s);
}
