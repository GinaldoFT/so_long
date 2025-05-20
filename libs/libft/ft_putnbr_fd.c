/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:43:49 by ginfranc          #+#    #+#             */
/*   Updated: 2025/04/13 19:03:40 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	str = (n % 10) + '0';
	write(fd, &str, 1);
}
