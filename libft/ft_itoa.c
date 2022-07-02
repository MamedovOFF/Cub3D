/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:13:25 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/16 17:40:18 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_string(char *res, int n, int len, int is_neg)
{
	int	i;

	i = is_neg;
	if (is_neg)
		res[0] = '-';
	res[len] = 0;
	while (i < len)
	{
		res[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
}

static void	ft_strrev(char *str, int is_neg)
{
	int		i;
	int		k;
	int		j;
	char	t;

	j = ft_strlen(str) - 1;
	k = j / 2;
	i = is_neg;
	while (i <= k)
	{
		t = str[j];
		str[j] = str[i];
		str[i] = t;
		i++;
		j--;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		is_neg = 1;
		n = -n;
	}
	len = find_len(n) * sizeof(char) + is_neg;
	res = (char *) malloc (len + 1);
	if ((void *)0 == res)
		return ((void *)0);
	fill_string(res, n, len, is_neg);
	ft_strrev(res, is_neg);
	return (res);
}
