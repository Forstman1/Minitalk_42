/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:04:26 by sahafid           #+#    #+#             */
/*   Updated: 2021/12/05 18:08:45 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isprint(char c)
{
	if (c == 'd' || c == 'i' \
	||c == 'x' || c == 'X' \
	|| c == 'u' || c == 's' \
	|| c == 'c' || c == 'p' \
	|| c == '%')
		return (1);
	else
		return (0);
}

static void	checkallcases(char *str, int *i, int *len, va_list *ptr)
{
	int	check;

	check = 0;
	if ((str[*i] == ' ' || str[*i] == '+') && \
	(str[*i + 1] == 'd' || str[*i + 1] == 'i'))
	{
		check = va_arg((*ptr), int);
		checkpluscase((char *)str, i, check, len);
		checkspacecase((char *)str, i, check, len);
	}
	else if (str[*i] == '#' && (str[*i + 1] == 'x' || str[*i + 1] == 'X'))
	{
		(*i)++;
		check = va_arg((*ptr), int);
		checksharpcase((char *)str, i, len, check);
	}
	else if (isprint(str[*i]))
		mandatorycases((char *)str, i, len, ptr);
	else
		write(1, &str[*i], 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		len;

	len = 0;
	i = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			checkallcases((char *)str, &i, &len, &ptr);
		}
		else
			putchar_fd(str[i], &len);
		i++;
	}
	va_end(ptr);
	return (len);
}
