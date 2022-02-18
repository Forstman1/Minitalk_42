/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:55:54 by sahafid           #+#    #+#             */
/*   Updated: 2021/07/10 11:20:33 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

static void	ft_putnbr1(unsigned int nbr1, char *base, int *len)
{
	if (nbr1 >= 0 && nbr1 < 16)
	{
		write(1, &base[nbr1], 1);
		(*len) += 1;
	}
	else if (nbr1 >= 16)
	{
		ft_putnbr1((nbr1 / 16), base, len);
		ft_putnbr1((nbr1 % 16), base, len);
	}
}

static void	ft_putnbr2(unsigned long nbr1, char *base, int *len)
{
	if (nbr1 >= 0 && nbr1 < 16)
	{
		write(1, &base[nbr1], 1);
		(*len) += 1;
	}
	else if (nbr1 >= 16)
	{
		ft_putnbr2((nbr1 / 16), base, len);
		ft_putnbr2((nbr1 % 16), base, len);
	}
}

void	ft_putnbr_base(long long nbr, char *base, int *len, char c)
{
	long long	nbr1;

	nbr1 = nbr;
	if (c == 'p')
		ft_putnbr2(nbr1, base, len);
	else
		ft_putnbr1(nbr1, base, len);
}
