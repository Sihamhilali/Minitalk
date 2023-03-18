/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:13:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/01/16 14:15:43 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fsign1(int signal, siginfo_t *in, void *context)
{
	static char	c = 0xFF;
	static int	i;
	static int	bit = 0;

	(void)context;
	if (i != in->si_pid)
	{
		i = in->si_pid;
		c = 0xFF;
		bit = 0;
	}
	if (signal == SIGUSR1)
		c ^= 1 << bit;
	else if (signal == SIGUSR2)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = &fsign1;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
