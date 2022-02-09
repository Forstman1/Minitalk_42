/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:14:48 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 12:17:13 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*dest;
	char	*a;

	src_len = ft_strlen(src);
	a = (char *)src;
	dest = (char *)malloc(src_len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, a);
	return (dest);
}
