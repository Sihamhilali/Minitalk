/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:40:17 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/14 16:09:03 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ad_nbrhexa(unsigned long long n, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		ad_nbrhexa(n / 16, count);
		ad_nbrhexa(n % 16, count);
	}
	else if (n < 16)
	{
		ft_putchar(hex[n % 16], count);
	}
}

void	address(unsigned long long n, int *count)
{
	ft_putstr("0x", count);
	ad_nbrhexa(n, count);
}
