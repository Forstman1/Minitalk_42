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
#include "Printf/ft_printf.h"
#include <sys/signal.h>


int x = 0;

void    convertingtoascii(int *count)
{
    int i;
    int decimal;
    int weight;
    int rem;

    rem = 0;
    decimal = 0;
    weight = 1;
    i = 7;

    while (i >= 0)
    {
        rem = count[i];
        decimal = decimal + rem*weight;
        weight = weight*2;
        i--;
    }
    ft_putchar_fd(decimal, 1);
    i = 7;
    while (i >= 0)
    {
        count[i] = 0;
        i--;
    }
}

void    test(int user)
{
    static int i;
    static int count[8] = {0};
    
    if (!i)
        i = 0;
    if (user == SIGUSR1)
    {
        count[i] = 1;
        i++;
        if (i == 8)
        {
            i = 0;
            convertingtoascii(count);
        }
    }
    else if (user == SIGUSR2)
    {
        count[i] = 0;
        i++;
        if (i == 8)
        {
            i = 0; 
            convertingtoascii(count);
        }
    }
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
    sa.sa_flags = SA_RESTART;
	sa.sa_handler = &test;

    ft_printf("%d\n", getpid());

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    while(1)
        sleep(1);
    
    return 0;
}
