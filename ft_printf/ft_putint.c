/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:40:19 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/14 15:55:16 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	nb = n;
	if (nb <= 9)
	{
		ft_putchar(nb + '0', count);
	}
	else
	{
		ft_putnbr(nb / 10, count);
		ft_putchar((nb % 10) + '0', count);
	}
}
