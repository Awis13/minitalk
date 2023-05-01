/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:25:23 by nipostni          #+#    #+#             */
/*   Updated: 2023/04/26 17:13:00 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	char_to_bit(char c, int bits[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		bits[i] = (c >> i) & 1;
		i++;
	}
	return (0);
}

void	send_bit(pid_t server_pid, int bit)
{
	if (bit == 1)
	{
		if (kill(server_pid, SIGUSR1) == -1)
		{
			ft_printf("Error sending signal");
			exit(2);
		}
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
		{
			ft_printf("Error sending signal");
			exit(2);
		}
	}
}

void	send_string(pid_t server_pid, char *str)
{
	int	i;
	int	bits[8];
	int	j;

	i = 0;
	while (str[i])
	{
		char_to_bit(str[i], bits);
		j = 0;
		while (j < 8)
		{
			send_bit(server_pid, bits[j]);
			usleep(100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	int		bits[8];

	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <string>\n", argv[0]);
		return (1);
	}
	server_pid = atoi(argv[1]);
	send_string(server_pid, argv[2]);
	return (0);
}
