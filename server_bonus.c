/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:25:33 by selhilal          #+#    #+#             */
/*   Updated: 2023/01/16 14:48:51 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	fsign2(int signal, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	i;
	static int	bit = 0;

	(void)context;
	if (i != info->si_pid)
	{
		i = info->si_pid;
		bit = 0;
		c = 0xFF;
	}
	if (signal == SIGUSR1)
		c ^= 1 << bit;
	else if (signal == SIGUSR2)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		if (!c)
			kill(info->si_pid, SIGUSR2);
		bit = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	si;
	pid_t				pid;

	si.sa_sigaction = fsign2;
	si.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL);
	while (1)
		pause();
	return (0);
}
