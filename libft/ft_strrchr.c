/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:15:39 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/14 17:39:39 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*h;
	char	a;
	int		j;

	h = (char *)str;
	j = 0;
	a = (char) c;
	while (h[j])
		j++;
	while (j >= 0)
	{
		if (h[j] == a)
			return (&h[j]);
		j--;
	}
	return (0);
}
