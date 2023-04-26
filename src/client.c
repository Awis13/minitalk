/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:25:23 by nipostni          #+#    #+#             */
/*   Updated: 2023/04/26 16:43:02 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"
#include "include/ft_printf.h"
#include "include/libft.h"

int char_to_bit(char c, int bits[8])
{
	int i;

	i = 0;
	while (i < 8)
	{
		bits[i] = (c >> i) & 1;
		i++;
	}
	return (0);
}
	


int main(int argc, char *argv[])
{
	int bits[8];
	char test_char = argv[1][0];
    if (argc != 2)
    {
        printf("Usage: %s <server_pid>\n", argv[0]);
        return 1;
    }

	char_to_bit(test_char, bits);
	int i = 0;
	while (i < 8)
	{
		printf("%d", bits[i]);
		i++;
	}
    // pid_t server_pid = atoi(argv[1]);

    // if (kill(server_pid, SIGUSR1) == -1)
    // {
    //     perror("Error sending signal");
    //     return 2;
    // }

    // printf("Signal sent successfully\n");
    return 0;
}