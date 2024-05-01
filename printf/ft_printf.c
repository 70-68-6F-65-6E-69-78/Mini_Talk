/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:27:16 by adbourji          #+#    #+#             */
/*   Updated: 2023/12/13 16:23:59 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * A ft_printf function tailored to match printf().
 * Controls output that is formatted based on the given format string.
 */

static int	ft_check_format(char x, va_list list)
{
	int	count;

	count = 0;
	if (x == 'c')
		count = ft_putchar(va_arg(list, int));
	else if (x == 's')
		count = ft_putstr(va_arg(list, char *));
	else if (x == 'p')
	{
		count = ft_putstr("0x");
		count += ft_putnbr_base2(va_arg(list, unsigned long));
	}
	else if (x == 'd' || x == 'i')
		count = ft_putnbr(va_arg(list, int));
	else if (x == 'u')
		count = ft_putnbr_base(va_arg(list, unsigned int), "0123456789");
	else if (x == 'x')
		count = ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	else if (x == 'X')
		count = ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (x == '%')
		count = ft_putchar('%');
	else
		count = ft_putchar(x);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			count += ft_check_format(format[i + 1], list);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}

/*
int	main(void)
{
	int	test;

	test = ft_printf("\n\tTESTING ft_printf:\n\n");

	test = ft_printf("Character: %c\n", 'A');
	test = ft_printf("String: %s\n", "Hello World!");
	test = ft_printf("Integer (%%d): %d\n", 1337);
	test = ft_printf("Integer (%%i): %i\n", 42);
	test = ft_printf("Unsigned Integer (%%u): %u\n", 2023);
	test = ft_printf("Hexadecimal (%%x): %x\n", 255);
	test = ft_printf("HEXADECIMAL (%%X): %X\n", 127);
	test = ft_printf("Pointer Address: %p\n", (void *)0);
	test = ft_printf("Percentage (%%%): %%\n");

	test = ft_printf("NULL String: %s\n", NULL);
	test = ft_printf("Large Integer: %d\n", 2147483647);
	test = ft_printf("Negative Large Integer: %d\n", -2147483648);

	test = ft_printf("Combined: %c %s %d", 'L', "LEET", 1337);
}
*/
