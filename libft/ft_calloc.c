/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:12:45 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 12:14:41 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	b;

	i = 0;
	ptr = (char *)malloc(n * size);
	if (!ptr)
		return (0);
	b = n * size;
	while (i < b)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
