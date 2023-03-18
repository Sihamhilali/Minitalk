/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:08:21 by selhilal          #+#    #+#             */
/*   Updated: 2023/01/16 10:21:01 by selhilal         ###   ########.fr       */
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

void	sigh(char *m, int pid)
{
	int	i;
	int	j;

	j = 0;
	while (m[j])
	{
		i = 0;
		while (i < 8)
		{
			if (m[j] & (1 << i))
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
			i++;
		}
		j++;
	}
}

int	main(int argc,	char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf(" client invalid\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("negative pid\n");
		exit(1);
	}
	sigh(argv[2], pid);
	return (0);
}
