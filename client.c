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
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "Printf/ft_printf.h"
#include <signal.h>

void	bitshifting(int i, int fd)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (i & (128 >> j))
		{
			kill(fd, SIGUSR1);
			usleep(500);
		}
		else
		{
			kill(fd, SIGUSR2);
			usleep(500);
		}
		j++;
	}
}

void	send(int user)
{
	if (user == SIGUSR1)
		printf("Message Sent\n");
}

void	convertingascii(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		bitshifting(str[i], fd);
		i++;
	}
	bitshifting('\0', fd);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					fd;

	fd = 0;
	if (argc == 3)
	{
		sa.sa_handler = &send;
		fd = ft_atoi(argv[1]);
		sigaction(SIGUSR1, &sa, NULL);
		convertingascii(argv[2], fd);
	}
	return (0);
}
