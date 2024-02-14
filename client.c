/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:39:28 by nkarabul          #+#    #+#             */
/*   Updated: 2024/02/10 16:38:20 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = str[i] - '0' + (res * 10);
		i++;
	}
	return (res * sign);
}

void	sendchar_to_server(int pid_id, char msj)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if ((msj >> bit) & 1)
			kill(pid_id, SIGUSR1);
		else
			kill(pid_id, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid_name;
	int	i;

	i = 0;
	pid_name = 0;
	if (ac != 3)
		ft_printf("Wrong format, try this : ./client <PID> <MESSAGE>");
	if (ac == 3)
	{
		pid_name = ft_atoi(av[1]);
		while (av[2][i] != '\0')
			sendchar_to_server(pid_name, av[2][i++]);
		sendchar_to_server(pid_name, '\n');
		sendchar_to_server(pid_name, '\0');
	}
	return (0);
}
