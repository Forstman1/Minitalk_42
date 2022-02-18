/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:08:22 by sahafid           #+#    #+#             */
/*   Updated: 2021/12/05 18:08:23 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_fd(int i, int *len)
{
	write(1, &i, 1);
	(*len)++;
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
	}
	else if (n < 0 && n > -2147483648)
	{
		putchar_fd('-', len);
		ft_putnbr(n * (-1), len);
	}
	else if (n >= 0 && n < 10)
	{
		putchar_fd(n + '0', len);
	}
	else if (n >= 10 && n <= 2147483647)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (s[i])
	{
		(*len) += write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_u(unsigned int n, int *len)
{
	if (n >= 0 && n < 10)
		putchar_fd(n + '0', len);
	else if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
}
