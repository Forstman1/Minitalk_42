/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:12:11 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 11:21:52 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;
	char	*a;

	a = (char *)src;
	i = 0;
	len = 0;
	while (a[len] != '\0')
		len++;
	if (n == 0)
		return (len);
	while (a[i] != '\0' && i + 1 < n)
	{
		dst[i] = a[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
