/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:15:35 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/15 14:47:29 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	size_t				i;
	unsigned char		*new_dest;
	unsigned const char	*new_src;

	i = 0;
	new_dest = (unsigned char *) dest;
	new_src = (unsigned const char *)source;
	if (dest || source)
	{
		while (i < count)
		{
			new_dest[i] = new_src[i];
			i++;
		}
	}
	return (dest);
}
