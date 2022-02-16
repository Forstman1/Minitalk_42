/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:38:37 by sahafid           #+#    #+#             */
/*   Updated: 2022/02/07 13:38:40 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "Printf/ft_printf.h"
#include "minitalk.h"
#include <sys/signal.h>

int	g_i = 0;

void	sending_utils(int *count, int fd)
{
	int	j;

	j = 0;
	while (j <= 7)
	{
		if (count[j] != 0 && count[j] != 1 && count[j] != 2)
			count[j] = 0;
		if (count[j] == 1)
		{
			kill(fd, SIGUSR1);
			usleep(500);
		}
		if (count[j] == 0)
		{
			kill(fd, SIGUSR2);
			usleep(500);
		}
		if (count[j] == 2)
		{
			kill(fd, SIGUSR2);
			usleep(500);
		}
		j++;
	}
}

void	convertingbinary(int i, int fd, int *j)
{
	if (i == 0)
	{
		j[g_i] = 2;
		g_i++;
	}
	else if (i == 1)
	{
		j[g_i] = 1;
		g_i++;
	}
	else if (i > 1)
	{
		convertingbinary((i / 2), fd, j);
		convertingbinary((i % 2), fd, j);
	}
}

void	sendingchar(char c, int fd)
{
	int	count[8] = {0};

	g_i = 0;
	convertingbinary(c, fd, count);
	sending(count, fd);
	sending_utils(count, fd);
}

void	send(int user)
{
	if (user == SIGUSR1)
		printf("Message received From SIGUSR1\n");
	if (user == SIGUSR2)
		printf("Message received From SIGUSR2\n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					i;
	int					fd;
	char				*s;

	fd = 0;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &send;
	fd = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	convertingascii(argv[2], fd);
	return (0);
}
