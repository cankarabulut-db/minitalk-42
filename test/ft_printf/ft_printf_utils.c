/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:44:57 by nkarabul          #+#    #+#             */
/*   Updated: 2024/01/14 17:37:12 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int a)
{
	int	i;

	i = 0;
	if (a == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (a < 0)
	{
		i += ft_putchar('-');
		a = -a;
	}
	if (a >= 10)
		i += ft_putnbr(a / 10);
	i += ft_putchar((a % 10) + '0');
	return (i);
}

int	ft_puthex(unsigned int a, int c)
{
	int	count;

	count = 0;
	if (a >= 16)
		count += ft_puthex(a / 16, c);
	if (c == 1)
		count += ft_putchar("0123456789abcdef"[a % 16]);
	else
		count += ft_putchar("0123456789ABCDEF"[a % 16]);
	return (count);
}

int	ft_puthexp(unsigned long a, int c)
{
	int	count;

	count = 0;
	if (c == 1)
	{
		count += ft_putchar('0');
		count += ft_putchar('x');
	}
	if (a >= 16)
		count += ft_puthexp(a / 16, 0);
	count += ft_putchar("0123456789abcdef"[a % 16]);
	return (count);
}

int	ft_putuns(unsigned int a)
{
	int	count;

	count = 0;
	if (a >= 10)
		count += ft_putuns(a / 10);
	count += ft_putchar(a % 10 + 48);
	return (count);
}
