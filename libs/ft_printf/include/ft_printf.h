/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:54:54 by ginfranc          #+#    #+#             */
/*   Updated: 2025/04/19 13:11:48 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putstr_len(char *str);
int		ft_putchar_len(char c);
void	ft_verific(const char *str, int *count, va_list args);
void	ft_putnbr_len(long int nb, int *count);
void	ft_uputnbr_len(unsigned int nb, int *count);
void	ft_puthex_len(unsigned long int nb, int *count);
void	ft_puthexm_len(unsigned long int nb, int *count);
void	ft_putptr_len(const void *ptr, int *count);

#endif
