/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:18:40 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/15 14:47:32 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	size_t	i;

	if (dest || source)
	{
		if ((unsigned char *)dest < (unsigned char *)source)
		{
			i = 0;
			while (n--)
			{
				((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
				i++;
			}
		}
		else
		{
			while (n--)
			{
				((unsigned char *)dest)[n] = ((unsigned char *)source)[n];
			}
		}
	}
	return (dest);
}
