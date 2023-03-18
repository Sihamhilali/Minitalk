/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:40:23 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/14 16:16:14 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	nbrhexa(unsigned int n, char var, int *count)
{
	char	*hex;

	if (var == 'X')
		hex = "0123456789ABCDEF";
	else if (var == 'x')
		hex = "0123456789abcdef";
	if (n >= 16)
	{
		nbrhexa(n / 16, var, count);
		nbrhexa(n % 16, var, count);
	}
	else if (n < 16)
	{
		ft_putchar(hex[n % 16], count);
	}
}
