/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:25:25 by nipostni          #+#    #+#             */
/*   Updated: 2023/04/26 16:27:14 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include "include/libft.h"

void signal_handler(int sig)
{
	ft_printf("Signal received: %d\n", sig);
}

char bits_to_char(int bits[8])
{
	char c;
	int i;

	c = 0;
	i = 0;

	while (i < 8)
	{
		c += bits[i] << i;
		i++;
	}
	return (c);
}

int main(void)
{
	// int bits[8];
	pid_t pid;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	int bits[8] = {1,0,0,0,0,0,1,0};
	printf("%c\n", bits_to_char(bits));
	signal(SIGUSR1, signal_handler);
	while (1)
	{
		pause();
	}
	return 0;
}

