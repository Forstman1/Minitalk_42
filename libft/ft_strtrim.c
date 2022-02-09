/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:50:17 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 12:31:09 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	depart(int i, char *b, char *a)
{
	int	o;

	o = 0;
	while (a[i])
	{
		o = 0;
		while (b[o])
		{
			if (b[o] == a[i])
				break ;
			o++;
		}
		if (b[o] != a[i])
			break ;
		i++;
	}
	return (i);
}

static char	*newarray(int i, int j, char *a)
{
	int		o;
	char	*c;

	o = 0;
	c = NULL;
	c = (char *)malloc((j - i + 2) * sizeof(char));
	if (!c)
		return (NULL);
	while (i <= j)
	{
		c[o] = a[i];
		o++;
		i++;
	}
	c[o] = '\0';
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*a;
	char	*b;

	i = 0;
	j = 0;
	a = (char *)s1;
	b = (char *)set;
	if (!(s1) || !(set))
		return (NULL);
	i = depart(i, b, a);
	j = ft_strlen(a);
	return (newarray(i, j, a));
}
