/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:33:35 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 10:38:40 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int i, size_t len)
{
	char	*c;
	size_t	a;

	a = 0;
	c = (char *)ptr;
	while (a < len)
	{
		c[a] = (unsigned char)i;
		a++;
	}
	return (ptr);
}
