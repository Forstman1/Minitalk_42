/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:03:59 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/12 21:04:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*root;

	root = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (root->next != NULL)
			root = root->next;
		root->next = new;
	}
}
