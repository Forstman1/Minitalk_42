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

  

void    convertingbinary(int i, int fd)
{
    printf("%c\n", i);
    if (i == 0)
        kill(fd, SIGUSR1);
    else if (i == 1)
        kill(fd, SIGUSR2);
    else
    {
        
        convertingbinary((i / 2), fd);
        convertingbinary((i % 2), fd);
    }
}

void    convertingascii(char *str, int fd)
{
    int i;

    i = 0;
    while (str[i])
    {
        printf("%c\n", str[i]);
        convertingbinary(str[i], fd);
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
 