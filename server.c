/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:39:22 by nkarabul          #+#    #+#             */
/*   Updated: 2024/02/10 16:37:34 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	terminal(int pid)
{
	ft_printf("Procces ID : %d\n", pid);
	ft_printf("Message awaited...\n");
}

void	handler(int signal)
{
	static int	bit = 0;
	static char	c;

	if (signal == SIGUSR1)
		c = ((1 << bit) | c);
	if (signal == SIGUSR2)
		c = ((0 << bit) | c);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	pid = getpid();
	if (ac != 1)
	{
		ft_printf("Error: wrong format. Try this : ./server\n");
		return (0);
	}
	terminal(pid);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		pause();
	return (0);
}
