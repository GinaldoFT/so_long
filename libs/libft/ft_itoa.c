/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:25:17 by ginfranc          #+#    #+#             */
/*   Updated: 2025/04/14 09:47:03 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test(long int *n)
{
	int		len;
	long	temp;

	len = 1;
	if (*n < 0)
	{
		len++;
		*n *= -1;
	}
	temp = *n;
	while (temp > 9)
	{
		len++;
		temp /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	num;

	num = n;
	len = test(&num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
