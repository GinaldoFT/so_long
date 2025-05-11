/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:29:24 by ginfranc          #+#    #+#             */
/*   Updated: 2025/04/11 10:57:38 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	source_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	dest_len = ft_strlen(dest);
	source_len = ft_strlen(src);
	if (dstsize <= dest_len)
		return (source_len + dstsize);
	while (src[i] && dstsize - 1 > dest_len + i)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + source_len);
}
