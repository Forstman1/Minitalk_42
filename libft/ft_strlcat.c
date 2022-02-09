/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:22:09 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 12:12:34 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len;
	size_t	o;
	size_t	i;
	char	*a;

	a = (char *)src;
	i = 0;
	len = ft_strlen(dst);
	o = ft_strlen(a);
	if (n < len)
		o += n;
	else if (n >= len)
		o += len;
	while (a[i] != 0 && len + 1 < n)
	{
		dst[len] = a[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	return (o);
}
