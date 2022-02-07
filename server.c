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


int x = 0;

void    client(int sig)
{
    if (x == 0)
    {
        printf("im working");
        printf("%d", sig);
    }
}

int main(int argc, char *argv[])
{
    struct sigaction sa = { 0 };
    sa.sa_handler = &client;

    printf("%d", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    
    sleep(10);

    return 0;
}
