/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:30:03 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/11 15:30:04 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char i, int fd)
{
	write(fd, &i, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0 && n > -2147483648)
	{
		ft_putchar('-', fd);
		ft_putnbr_fd(n * (-1), fd);
	}
	else if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0', fd);
	}
	else if (n >= 10 && n <= 2147483647)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
