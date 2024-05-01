/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:15:50 by adbourji          #+#    #+#             */
/*   Updated: 2023/12/13 16:03:06 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Writes an integer to the standard output.
 * Handles negative values and minimum integer case.
*/

int	ft_putnbr(int nbr)
{
	int	res;

	res = 0;
	if (nbr == -2147483648)
		res += ft_putstr("-2147483648");
	else if (nbr < 0)
	{
		res += ft_putchar('-');
		nbr = -nbr;
		res += ft_putnbr(nbr);
	}
	else if (nbr > 9)
	{
		res += ft_putnbr(nbr / 10);
		res += ft_putnbr(nbr % 10);
	}
	else
		res += ft_putchar(nbr + 48);
	return (res);
}
