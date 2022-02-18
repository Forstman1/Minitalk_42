/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mandatory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:46:19 by sahafid           #+#    #+#             */
/*   Updated: 2021/12/08 13:48:43 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mandatorycases(char *str, int *i, int *len, va_list *ptr)
{
	if (str[(*i)] == 'd' || str[(*i)] == 'i')
		ft_putnbr(va_arg((*ptr), int), len);
	else if (str[(*i)] == 'c')
		putchar_fd(va_arg((*ptr), int), len);
	else if (str[(*i)] == 's')
		ft_putstr(va_arg((*ptr), char *), len);
	else if (str[(*i)] == 'u')
		ft_putnbr_u(va_arg((*ptr), unsigned int), len);
	else if (str[(*i)] == 'p')
	{
		(*len) += write(1, "0x", 2);
		ft_putnbr_base(va_arg((*ptr), long), "0123456789abcdef", len, 'p');
	}
	else if (str[(*i)] == '%')
		(*len) += write(1, "%", 1);
	else if (str[(*i)] == 'x')
		ft_putnbr_base(va_arg((*ptr), int), "0123456789abcdef", len, 'x');
	else if (str[(*i)] == 'X')
		ft_putnbr_base(va_arg((*ptr), int), "0123456789ABCDEF", len, 'X');
}
