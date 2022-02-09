/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:57:55 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/09 16:57:58 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convertingnegat(long int y, char *a, long int o)
{
	long int	res;
	long int	store;

	store = 0;
	res = o;
	while (y > 0)
	{
		store = res % 10;
		a[y] = store + '0';
		store = 0;
		res = o / 10;
		o = res;
		y--;
	}
	return (a);
}

static char	*convertingpos(long int y, char *a, int n)
{
	long int	res;
	long int	store;

	store = 0;
	res = n;
	while (y > 0)
	{
		store = res % 10;
		a[y - 1] = store + '0';
		store = 0;
		res = n / 10;
		n = res;
		y--;
	}
	return (a);
}

static char	*negatifcase(int n, long int y)
{
	char		*a;
	long int	res;
	long int	o;
	long int	l;

	res = n;
	o = (long int)n;
	while (o != '\0')
	{
		o = o / 10;
		y++;
	}
	l = y;
	a = (char *)malloc((y + 2) * sizeof(char));
	if (!a)
		return (0);
	a[0] = '-';
	res = res * -1;
	o = res;
	a = convertingnegat(y, a, o);
	a[l + 1] = '\0';
	return (a);
}

static char	*positifcase(int n, long int y)
{
	long int	res;
	long int	l;
	char		*a;

	res = n;
	while (n != '\0')
	{
		n = n / 10;
		y++;
	}
	l = y;
	a = (char *)malloc((y + 1) * sizeof(char));
	if (!a)
		return (0);
	n = res;
	a = convertingpos(y, a, n);
	a[l] = '\0';
	return (a);
}

char	*ft_itoa(int n)
{
	char		*a;
	long int	y;

	y = 0;
	if (n == 0)
	{
		a = (char *)malloc(2 * sizeof(char));
		if (!a)
			return (0);
		a[0] = '0';
		a[1] = '\0';
		return (a);
	}
	if (n > 0)
		return (positifcase(n, y));
	else
		return (negatifcase(n, y));
}
