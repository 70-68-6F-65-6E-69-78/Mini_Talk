/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:49:28 by adbourji          #+#    #+#             */
/*   Updated: 2024/03/19 08:33:14 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk_bonus.h"

void	ft_handle_confirmation(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("+---------------------+\n");
		ft_printf("|    SUCCESSFULLY !   |\n");
		ft_printf("|        125%          |\n");
		ft_printf("^---------------------^\n");
	}
}

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10 + (str[i] - '0'));
		i++;
	}
	return (res * sign);
}

void	ft_send_character(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Usage: %s [PID] [message]\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_printf("Unable to verify PID : %d\n", pid);
		return (1);
	}
	while (argv[2][i])
	{
		ft_send_character(pid, argv[2][i]);
		usleep(500);
		i++;
	}
	signal(SIGUSR2, ft_handle_confirmation);
	ft_send_character(pid, '\0');
	return (0);
}
