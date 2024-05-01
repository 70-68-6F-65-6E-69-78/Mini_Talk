/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:19:59 by adbourji          #+#    #+#             */
/*   Updated: 2023/12/13 15:59:03 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/*
 * FT_PRINTF - Costum Printf Function
 *
 * Devloped by Abourji
 * Date : 2023-12-09 -> 2023-12-13
*/

int	ft_putchar(int c);
int	ft_putnbr_base(unsigned int nbr, char *format);
int	ft_putnbr_base2(unsigned long nbr);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);

#endif
