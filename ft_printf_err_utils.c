/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:43:23 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/24 13:24:06 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_err.h"

int	ft_putchar_err(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_putstr_err(char *str)
{
	int	count;
	int	i;

	if (!str)
	{
		write(2, "(null)", 6);
		return (6);
	}
	count = 0;
	i = 0;
	while (str[i])
	{
		count += ft_putchar_err(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr_err(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(2, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar_err('-');
		n = n * -1;
	}
	if (n < 10)
		count += ft_putchar_err(n + '0');
	else
	{
		count += ft_putnbr_err(n / 10);
		count += ft_putnbr_err(n % 10);
	}
	return (count);
}
