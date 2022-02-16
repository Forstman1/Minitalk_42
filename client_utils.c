/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:52:58 by sahafid           #+#    #+#             */
/*   Updated: 2022/02/13 16:53:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sending(int *count, int fd)
{
	int	j;
	int	i;
	int	temp;

	j = 0;
	i = 0;
	temp = 0;
	while (j <= 7)
	{
		if (count[j] == 0)
			i++;
		j++;
	}
	while (i > 0)
	{
		j = 7;
		while (j > 0)
		{
			temp = count[j - 1];
			count[j - 1] = count[j];
			count[j] = temp;
			j--;
		}
		i--;
	}
}

void	convertingascii(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		sendingchar(str[i], fd);
		i++;
	}
}
