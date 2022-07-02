/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:24:29 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/15 15:24:50 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t				i;
	const unsigned char	*u_str1;
	const unsigned char	*u_str2;

	u_str1 = (const unsigned char *) str1;
	u_str2 = (unsigned const char *) str2;
	i = 0;
	while ((*u_str1 || *u_str2) && i < n)
	{
		if (*u_str1 != *u_str2)
		{
			if (*u_str1 > *u_str2)
				return (1);
			else if (*u_str1 < *u_str2)
				return (-1);
		}
		u_str1++;
		u_str2++;
		i++;
	}
	return (0);
}
