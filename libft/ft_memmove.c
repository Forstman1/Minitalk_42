/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:47:13 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 11:11:45 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *) dst;
	b = (char *) src;
	if (a == b)
		return (b);
	if (a < b)
		return (ft_memcpy(a, b, n));
	else
	{
		n -= 1;
		while (0 < n + 1)
		{
			a[n] = b[n];
			n--;
		}
	}
	return (dst);
}
