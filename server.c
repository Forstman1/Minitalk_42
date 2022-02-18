/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:26:54 by sahafid           #+#    #+#             */
/*   Updated: 2022/02/07 12:26:55 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "Printf/ft_printf.h"
#include <signal.h>

void	checkend(int *count, int pid)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	while (i >= 0)
	{
		if (count[i] == 0)
			j++;
		else
			break ;
		i--;
	}
	if (j == 8)
	{
		usleep(500);
		kill(pid, SIGUSR1);
	}
}

void	reset(int *i, int *count)
{
	int	j;

	j = 7;
	*i = 0;
	while (j >= 0)
	{
		count[j] = 0;
		j--;
	}
}

void	convertingtoascii(int *count, int pid, int *j)
{
	int	i;
	int	decimal;
	int	weight;
	int	rem;

	*j = 0;
	rem = 0;
	decimal = 0;
	weight = 1;
	i = 7;
	while (i >= 0)
	{
		rem = count[i];
		decimal = decimal + rem * weight;
		weight = weight * 2;
		i--;
	}
	checkend(count, pid);
	ft_putchar_fd(decimal, 1);
	i = 7;
	while (i >= 0)
	{
		count[i] = 0;
		i--;
	}
}

void	send(int user, siginfo_t *var, void *ptr1)
{
	static int	i = 0;
	static int	count[8] = {0};
	static int	pid = 0;

	ptr1 = (void *)0;
	if (pid != var->si_pid)
	{
		pid = var->si_pid;
		reset(&i, count);
	}
	if (user == SIGUSR1)
	{
		count[i++] = 1;
		if (i == 8)
			convertingtoascii(count, pid, &i);
	}
	else if (user == SIGUSR2)
	{
		count[i++] = 0;
		if (i == 8)
			convertingtoascii(count, pid, &i);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	argv[1] = "";
	argc = 1;
	sa.sa_sigaction = send;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
