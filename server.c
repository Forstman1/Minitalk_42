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
#include <stdio.h>
#include <signal.h>
#include <sys/signal.h>


int x = 0;

void    test(int user)
{
    printf("%d", user);
    printf("im working\n");
}

void    client(int sig)
{
    printf("im working\n");
    printf("%d", sig);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    sa.sa_handler = &client;

    printf("%d\n", getppid());
    while(1)
    {
        signal(SIGUSR1, client);
        pause();
    }
    sleep(1);
    
    return 0;
}
