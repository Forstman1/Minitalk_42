/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:50:56 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 12:25:55 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	char	*b;
	char	*c;
	int		i;

	i = 0;
	a = (char *)s1;
	b = (char *)s2;
	if (!(s1) || !(s2))
		return (NULL);
	c = (char *)malloc((ft_strlen(a) + ft_strlen(b) + 1) * 1);
	if (!c)
		return (NULL);
	ft_strcpy(c, a);
	ft_strcat(c, b);
	return (c);
}
