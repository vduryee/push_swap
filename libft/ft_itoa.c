/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 00:25:52 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/20 17:19:42 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		len;

	nb = n;
	len = get_len(nb);
	res = (ft_calloc(sizeof(char), len + 1));
	if (!res)
		return (NULL);
	if (!n)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (res);
}

// #include <stdio.h>
// int main ()
// {
// 	long nb = 2147483649;
// 	printf("%s", ft_itoa(nb));
// }
