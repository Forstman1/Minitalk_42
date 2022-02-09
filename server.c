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
#include "libft/libft.h"
#include <sys/signal.h>


int x = 0;

void    test(int user)
{
    if (user == SIGUSR1)
        printf("\nReceive SIGUSR1\n");
    else if (user == SIGUSR2)
        printf("\nReceive SIGUSR2\n");
}


int main(int argc, char *argv[])
{

    printf("%d\n", getpid());
    if (signal(SIGUSR1, test) == SIG_ERR)
        printf("not received");
    else if (signal(SIGUSR2, test) == SIG_ERR)
        printf("not received"); 
    

    while(1)
    {
        sleep(1);
    }
    
    
    return 0;
}
