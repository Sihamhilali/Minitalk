/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:40:33 by selhilal          #+#    #+#             */
/*   Updated: 2022/11/15 15:12:31 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_printf_f(const char *formt, va_list arg, int i, int *rest)
{
	if (formt[i] == 'd' || formt[i] == 'i')
		ft_putnbr(va_arg(arg, int), rest);
	else if (formt[i] == 's')
		ft_putstr(va_arg(arg, char *), rest);
	else if (formt[i] == 'x' || formt[i] == 'X')
		nbrhexa(va_arg(arg, int), formt[i], rest);
	else if (formt[i] == 'c')
		ft_putchar(va_arg(arg, int), rest);
	else if (formt[i] == 'p')
		address(va_arg(arg, long), rest);
	else if (formt[i] == 'u')
		ft_putnbr_unsigned(va_arg(arg, int), rest);
	else if (formt[i] == '%')
		ft_putchar('%', rest);
	else
		ft_putchar(formt[i], rest);
}

int	ft_printf(const char *formt, ...)
{
	int		rest;	
	va_list	arg;
	int		i;

	i = 0;
	rest = 0;
	va_start(arg, formt);
	while (formt[i] != '\0')
	{
		if (write(1, "", 0) == -1)
			return (-1);
		if (formt[i] == '%' && formt[i + 1] == '\0')
			break ;
		if (formt[i] == '%')
			f_printf_f(formt, arg, ++i, &rest);
		else if (formt[i] != '%')
			ft_putchar(formt[i], &rest);
		i++;
	}
	va_end(arg);
	return (rest);
}
