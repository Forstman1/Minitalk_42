/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:42:59 by sahafid           #+#    #+#             */
/*   Updated: 2021/12/08 13:43:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checksharpcase(char *str, int *i, int *len, int check)
{
	if (str[(*i)] == 'x' && check != 0)
	{
		(*len) += write(1, "0x", 2);
		ft_putnbr_base(check, "0123456789abcdef", len, 'x');
	}
	else if (str[(*i)] == 'X' && check != 0)
	{
		(*len) += write(1, "0X", 2);
		ft_putnbr_base(check, "0123456789ABCDEF", len, 'X');
	}
	else if (check == 0)
	{
		(*len) += write(1, "0", 1);
	}
}

void	checkspacecase(char *str, int *i, int check, int *len)
{
	if (str[*i] == ' ' && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
	{
		if (check >= 0)
		{
			(*len) += write(1, " ", 1);
			ft_putnbr(check, len);
			(*i)++;
		}
		else
		{
			ft_putnbr(check, len);
			(*i)++;
		}
	}
}

void	checkpluscase(char *str, int *i, int check, int *len)
{
	if (str[*i] == '+' && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
	{
		if (check >= 0)
		{
			(*len) += write(1, "+", 1);
			ft_putnbr(check, len);
			(*i)++;
		}
		else
		{
			ft_putnbr(check, len);
			(*i)++;
		}
	}
}
