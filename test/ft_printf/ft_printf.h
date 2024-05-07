/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:50:42 by nkarabul          #+#    #+#             */
/*   Updated: 2024/01/14 17:42:35 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char a);
int	ft_putstr(char *str);
int	ft_putnbr(int a);
int	ft_putuns(unsigned int a);
int	ft_puthex(unsigned int a, int c);
int	ft_puthexp(unsigned long a, int c);
int	ft_printf(const char *str, ...);

#endif