/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:48:42 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/14 17:52:36 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**freecase(char	**b, char *a)
{
	size_t	t;

	t = 0;
	while (b[t])
	{
		free(b[t]);
		t++;
	}
	free(b);
	b = (char **)ft_calloc(1, sizeof(char *));
	free(a);
	return (b);
}

static char	**cpypast(size_t o, char *a, char **b, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	t;

	i = 0;
	j = 0;
	t = 0;
	while (i < o)
	{
		b[i] = ft_strdup(&a[j]);
		if (!b)
			return (freecase(b, a));
		while (j < len)
		{
			if (a[j + 1] && !a[j])
			{
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	free(a);
	return (b);
}

static int	numdelim(char *a, char c, size_t len)
{
	size_t	o;
	size_t	i;

	o = 0;
	i = 0;
	while (i < len)
	{
		if (a[i] == c)
			o++;
		if (a[i] == c)
			a[i] = '\0';
		i++;
	}
	return (o);
}

static char	**nullcase(char *a)
{
	char	**b;

	b = (char **)malloc(sizeof(char *) * 1);
	b[0] = NULL;
	if (a[0] != 0)
		b[0] = ft_strdup(a);
	else
		return (b);
	b[1] = NULL;
	return (b);
}

char	**ft_split(const char *s, char c)
{
	size_t	o;
	size_t	len;
	char	*a;
	char	**b;

	a = (char *)s;
	b = NULL;
	if (!s)
		return (NULL);
	if (c == 0)
		return (nullcase(a));
	a = ft_strtrim(s, &c);
	if (!a)
		return (NULL);
	len = ft_strlen(a);
	o = numdelim(a, c, len);
	if (a[0] == 0)
	{
		b = (char **)ft_calloc(1, sizeof(char *));
		return (free(a), b);
	}
	b = (char **)ft_calloc(++o + 1, sizeof(char *));
	b = cpypast(o, a, b, len);
	return (b);
}
