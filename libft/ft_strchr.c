/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:11:48 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 10:14:47 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*h;
	char	a;
	int		i;

	h = (char *)str;
	i = 0;
	a = (char)c;
	while (h[i] != '\0')
	{
		if (a == h[i])
			return (&h[i]);
		i++;
	}
	if (a == '\0')
		return (&h[i]);
	return (0);
}
