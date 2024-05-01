/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:27:46 by adbourji          #+#    #+#             */
/*   Updated: 2023/12/13 16:19:14 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Utility functions for handling base conversions and string lengths.
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, char *format)
{
	int				count;
	unsigned int	len;

	len = ft_strlen(format);
	count = 0;
	if (nbr >= len)
	{
		count += ft_putnbr_base(nbr / len, format);
		count += ft_putnbr_base(nbr % len, format);
	}
	else
		count += ft_putchar(format[nbr]);
	return (count);
}

int	ft_putnbr_base2(unsigned long nbr)
{
	int		count;
	char	*format;

	format = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_base2(nbr / 16);
		count += ft_putnbr_base2(nbr % 16);
	}
	else
		count += ft_putchar(format[nbr]);
	return (count);
}
