/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:25:25 by nipostni          #+#    #+#             */
/*   Updated: 2023/04/24 17:17:45 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include "include/libft.h"

void signal_handler(int sig)
{
	ft_printf("Signal received: %d\n", sig);
}

int main(void)
{
	pid_t pid;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	while (1)
	{
		pause();
	}
	return 0;
}

