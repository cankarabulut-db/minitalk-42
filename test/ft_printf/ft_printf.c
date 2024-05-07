/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:42:02 by nkarabul          #+#    #+#             */
/*   Updated: 2024/01/14 17:39:38 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ochecker(char a)
{
	if (a == 'c' || a == 's' || a == 'd' || a == 'i' || \
		a == 'u' || a == 'x' || a == 'X' || a == 'p' || a == '%')
		return (1);
	return (0);
}

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int	checkprint(va_list list, char a)
{
	if (a == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (a == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (a == 'd' || a == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (a == '%')
		return (ft_putchar('%'));
	else if (a == 'u')
		return (ft_putuns(va_arg(list, unsigned int)));
	else if (a == 'x')
		return (ft_puthex(va_arg(list, unsigned int), 1));
	else if (a == 'X')
		return (ft_puthex(va_arg(list, unsigned int), 0));
	else if (a == 'p')
		return (ft_puthexp(va_arg(list, unsigned long), 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%' && ochecker(str[i + 1]))
			len += checkprint(list, str[++i]);
		else if (str[i] == '%')
			len += ft_putstr("");
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (len);
}
