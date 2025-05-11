/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnumber.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:11:18 by ginfranc          #+#    #+#             */
/*   Updated: 2025/04/19 13:10:16 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(long int nb, int *count)
{
	char	c;

	if (nb < 0)
	{
		nb *= -1;
		*count += ft_putchar_len('-');
	}
	if (nb > 9)
		ft_putnbr_len(nb / 10, count);
	c = (nb % 10) + '0';
	*count += ft_putchar_len(c);
}

void	ft_uputnbr_len(unsigned int nb, int *count)
{
	char	c;

	if (nb > 9)
		ft_putnbr_len(nb / 10, count);
	c = (nb % 10) + '0';
	*count += ft_putchar_len(c);
}

void	ft_puthex_len(unsigned long int nb, int *count)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nb > 15)
		ft_puthex_len(nb / 16, count);
	i = nb % 16;
	*count += ft_putchar_len(base[i]);
}

void	ft_puthexm_len(unsigned long int nb, int *count)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb > 15)
		ft_puthexm_len(nb / 16, count);
	i = nb % 16;
	*count += ft_putchar_len(base[i]);
}

void	ft_putptr_len(const void *ptr, int *count)
{
	if (!ptr)
	{
		*count += ft_putstr_len("(nil)");
		return ;
	}
	*count += ft_putstr_len("0x");
	ft_puthex_len((unsigned long int)ptr, count);
}
