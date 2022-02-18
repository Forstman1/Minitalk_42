/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:18:18 by sahafid           #+#    #+#             */
/*   Updated: 2021/12/08 14:18:21 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	putchar_fd(int i, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr_base(long long nbr, char *base, int *len, char c);
void	ft_putnbr_u(unsigned int n, int *len);

/************MANDATORY************/

void	mandatorycases(char *str, int *i, int *len, va_list *ptr);

/************BONUS************/

void	checksharpcase(char *str, int *i, int *len, int check);
void	checkspacecase(char *str, int *i, int check, int *len);
void	checkpluscase(char *str, int *i, int check, int *len);

#endif
