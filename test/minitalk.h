/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:46:34 by nkarabul          #+#    #+#             */
/*   Updated: 2024/02/10 16:29:08 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <signal.h>

void	sendchar_to_server(int pid_id, char msj);
int		ft_atoi(const char *str);
void	handler(int signal);
void	terminal(int pid);

#endif