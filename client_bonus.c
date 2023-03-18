/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:25:54 by selhilal          #+#    #+#             */
/*   Updated: 2023/01/16 14:26:18 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	ft_atoi(char const *str)
{
	int	i;
	int	signe;
	int	somme;

	i = 0;
	signe = 1;
	somme = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		somme = somme * 10 + str[i] - '0';
		i++;
	}
	return (somme * signe);
}

void	message(int signal)
{
	(void)signal;
	write(1, "RECEIVED\n", 9);
}

void	sigh(char *m, pid_t pid)
{
	int	j;
	int	i;

	i = 0;
	while (1)
	{
		j = -1;
		while (++j < 8)
		{
			if (m[i] & (1 << j))
			{
				if (kill(pid, SIGUSR2) < 0)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) < 0)
					exit(1);
			}
			usleep(500);
		}
		if (!m[i])
			break ;
	i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf(" client invalid\n");
		exit(1);
	}
	signal(SIGUSR2, message);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("negative pid\n");
		exit(1);
	}
	sigh(av[2], pid);
	return (0);
}
