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
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "Printf/ft_printf.h"
#include <sys/signal.h>

int x = 0;

static void    sending(int *count, int fd)
{
    int j;
    int i;
    int temp;

    j = 0;
    i = 0;
    temp = 0;
    while(j <= 7)
    {
        if (count[j] == 0)
            i++;
        j++;
    }
    while(i > 0)
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
    j = 0;
    while(j <= 7)
    {
        if (count[j] != 0 && count[j] != 1 && count[j] != 2)
            count[j] = 0;
        if (count[j] == 1)
            kill(fd, SIGUSR1);
        if (count[j] == 0)
            kill(fd, SIGUSR2);
        if (count[j] == 2)
            kill(fd, SIGUSR2);
        usleep(500);
        j++;
    }
}

void    convertingbinary(int i, int fd, int *j)
{
    if (i == 0)
    {
        j[x] = 2;
        x++;
    }
    else if (i == 1)
    {
        j[x] = 1;
        x++;
    }
    else if (i > 1)
    {
        convertingbinary((i / 2), fd, j);
        convertingbinary((i % 2), fd, j);
    }
}

void    sendingchar(char c, int fd)
{
    int count[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    x = 0;
    convertingbinary(c, fd, count);
    sending(count, fd);
}



void    convertingascii(char *str, int fd)
{
    int i;


    i = 0;
    while (str[i])
    {
        sendingchar(str[i], fd);
        i++;
    }
}

void    send(int user)
{
    if (user == SIGUSR1)
        printf("Message received From SIGUSR1\n");
    if (user == SIGUSR2)
        printf("Message received From SIGUSR2\n");
}

int main(int argc, char *argv[])
{
    struct sigaction    sa;
    int i;
    int fd;
    char *s;

	fd = 0;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = &send;
    fd = ft_atoi(argv[1]);
    sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    convertingascii(argv[2], fd);
    return 0;
}
 