/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:40:08 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/14 15:56:00 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n <= 9)
	{
		ft_putchar(n + '0', count);
	}
	else
	{
		ft_putnbr_unsigned(n / 10, count);
		ft_putchar((n % 10) + '0', count);
	}
}
