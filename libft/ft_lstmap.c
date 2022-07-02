/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.C                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:38:42 by jchopped          #+#    #+#             */
/*   Updated: 2021/10/17 13:18:30 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new_list;

	p = NULL;
	if (!del || !f)
		return (NULL);
	while (lst)
	{
		new_list = ft_lstnew(f(lst->content));
		if ((void *)0 == new_list)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back (&p, new_list);
		lst = lst->next;
	}
	return (p);
}
