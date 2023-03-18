/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:40:13 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/14 16:06:20 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	if (!s)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}
