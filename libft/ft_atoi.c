/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:51:33 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/07 10:33:24 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *a)
{
	return (*a == '\t'
		|| *a == '\n'
		|| *a == '\v'
		|| *a == '\f'
		|| *a == '\r'
		|| *a == ' ');
}

int	ft_atoi(const char *str)
{
	char	*a;
	int		i;
	int		res;
	int		sign;

	a = (char *)str;
	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(&a[i]))
		i++;
	if (a[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (a[i] == '+')
		i++;
	while (a[i] >= '0' && a[i] <= '9')
		res = res * 10 + a[i++] - '0';
	return (res * sign);
}
