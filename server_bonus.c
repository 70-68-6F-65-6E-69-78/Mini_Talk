/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:52:50 by adbourji          #+#    #+#             */
/*   Updated: 2024/03/19 08:13:36 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk_bonus.h"

void	ft_handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	static int	bit_count;
	static int	byte_value;

	(void)context;
	if (signal == SIGUSR1)
		byte_value |= (0x01 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (byte_value == 0)
			kill (siginfo->si_pid, SIGUSR2);
		ft_printf("%c", byte_value);
		bit_count = 0;
		byte_value = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	(void)argv;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("Error !!\n");
		return (1);
	}
	ft_printf("The server PID : %d\n", pid);
	sa.sa_sigaction = ft_handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
