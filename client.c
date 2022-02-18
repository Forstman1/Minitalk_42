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
			kill(fd, SIGUSR1);
		else
			kill(fd, SIGUSR2);
		usleep(600);
		j++;
	}
}

void	send(int user)
{
	if (user == SIGUSR1)
		ft_printf("Message Sent\n");
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
	int					i;

	fd = 0;
	i = 0;
	sa.sa_handler = &send;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (ft_isalpha(argv[1][i]))
				return (0);
			i++;
		}
		fd = ft_atoi(argv[1]);
		if (fd == -1 || fd == 0 || fd == 1)
			return (0);
		sigaction(SIGUSR1, &sa, NULL);
		convertingascii(argv[2], fd);
	}
	return (0);
}
