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
#include <sys/signal.h>



void    reminder(int i, int fd, int *count)
{
    while ((*count) < 6)
    {
        kill(fd, SIGUSR1);
        (*count)++;
    }
}

void    convertingbinary(int i, int fd, int *j)
{
    printf("%d\n", i);
    if (i == 0)
    {
        kill(fd, SIGUSR1);
        (*j)++;
        sleep(1);
    }
    else if (i == 1)
    {
        kill(fd, SIGUSR2);
        (*j)++;
        sleep(1);
    }
    else if (i > 1)
    {
        convertingbinary((i / 2), fd, j);
        convertingbinary((i % 2), fd, j);
    }
}

void    convertingascii(char *str, int fd)
{
    int i;
    int count;


    i = 0;
    count = 0;
    while (str[i])
    { 
        count = 0;
        convertingbinary(str[i], fd, &count);
        reminder(str[i], fd, &count);
        i++;
    }
}


int main(int argc, char *argv[])
{
    int i;
    int fd;

	fd = 0;
    fd = ft_atoi(argv[1]);
    convertingascii(argv[2], fd);
    
    return 0;
}
 