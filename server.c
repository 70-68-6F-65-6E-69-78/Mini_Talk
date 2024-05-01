/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:29:46 by adbourji          #+#    #+#             */
/*   Updated: 2024/03/19 07:57:04 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	ft_btoa(int signal)
{
	static int	bit = 0;
	static int	binary_value = 0;

	if (signal == SIGUSR1)
		binary_value |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", binary_value);
		bit = 0;
		binary_value = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error!!");
		return (1);
	}
	pid = getpid();
	ft_printf("The PID: %d\n", pid);
	signal(SIGUSR1, ft_btoa);
	signal(SIGUSR2, ft_btoa);
	while (1)
	{
		pause();
	}
	return (0);
}
