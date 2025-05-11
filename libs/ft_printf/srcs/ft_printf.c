/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:28:18 by ginfranc          #+#    #+#             */
/*   Updated: 2025/04/19 13:18:20 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_verific(str, &count, args);
		}
		else
			count += ft_putchar_len(*str);
		str++;
	}
	va_end(args);
	return (count);
}

void	ft_verific(const char *str, int *count, va_list args)
{
	if (*str == 'c')
		*count += ft_putchar_len(va_arg(args, int));
	else if (*str == 's')
		*count += ft_putstr_len(va_arg(args, char *));
	else if (*str == '%')
		*count += ft_putchar_len('%');
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_len(va_arg(args, int), count);
	else if (*str == 'u')
		ft_uputnbr_len(va_arg(args, unsigned int), count);
	else if (*str == 'x')
		ft_puthex_len(va_arg(args, unsigned int), count);
	else if (*str == 'X')
		ft_puthexm_len(va_arg(args, unsigned int), count);
	else if (*str == 'p')
		ft_putptr_len(va_arg(args, void *), count);
}
