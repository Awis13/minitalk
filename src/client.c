/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:25:23 by nipostni          #+#    #+#             */
/*   Updated: 2023/04/24 17:19:40 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"
#include "include/ft_printf.h"
#include "include/libft.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <server_pid>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);

    if (kill(server_pid, SIGUSR1) == -1)
    {
        perror("Error sending signal");
        return 2;
    }

    printf("Signal sent successfully\n");
    return 0;
}