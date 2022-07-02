/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:14:08 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/17 11:23:52 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t				i;
	unsigned const char	*new_arr1;
	unsigned const char	*new_arr2;

	i = 0;
	new_arr1 = (unsigned const char *) arr1;
	new_arr2 = (unsigned const char *) arr2;
	while (i < n)
	{
		if (new_arr1[i] != new_arr2[i])
			return (new_arr1[i] - new_arr2[i]);
		i++;
	}
	return (0);
}
