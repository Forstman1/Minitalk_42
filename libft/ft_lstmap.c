/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:17:47 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/13 18:17:48 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*start;

	start = NULL;
	while (lst != NULL)
	{
		root = ft_lstnew(f(lst->content));
		if (!root)
		{
			ft_lstclear(&root, del);
			return (0);
		}
		ft_lstadd_back(&start, root);
		lst = lst->next;
	}
	return (start);
}
