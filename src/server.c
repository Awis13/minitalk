/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:25:25 by nipostni          #+#    #+#             */
/*   Updated: 2023/04/26 17:27:26 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include "include/libft.h"

int bits[8];
int bit_index;

char bits_to_char(int bits[8]);

void signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		bits[bit_index] = 1;
	}
	else if (sig == SIGUSR2)
	{
		bits[bit_index] = 0;
	}
	else
	{
		ft_printf("Error");
	}

	bit_index++;

	if (bit_index >= 8)
	{
		bit_index = 0;
		char c = bits_to_char(bits);
		ft_printf("%c", c);
	}
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

	pid_t pid;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (42)
	{
		pause();
	}
	return 0;
}

