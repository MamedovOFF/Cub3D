/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:15:19 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/15 15:18:07 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return ((void *) 0);
	size = sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1);
	new_s = (char *) malloc(size);
	if ((void *)0 == new_s)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s1[i])
		new_s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[j++] = s2[i++];
	new_s[j] = 0;
	return (new_s);
}
