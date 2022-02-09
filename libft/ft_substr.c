/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:51:12 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 12:24:03 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	buffersize(size_t o, unsigned int l, size_t len, char *a)
{
	while (a[l] && o < len)
	{
		l++;
		o++;
	}
	return (o);
}

static char	*nullcase(void)
{
	char	*b;
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	b = (char *)malloc(sizeof(char));
	b[0] = '\0';
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	char			*b;
	size_t			o;
	unsigned int	l;

	o = 0;
	if (!s)
		return (NULL);
	a = (char *)s;
	l = ft_strlen(a);
	if (start > l)
		return (nullcase());
	l = start;
	o = buffersize(o, l, len, a);
	b = (char *)malloc((o + 1) * sizeof(char));
	if (!b)
		return (NULL);
	o = 0;
	while (a[start] && o < len)
		b[o++] = a[start++];
	b[o] = '\0';
	return (b);
}
