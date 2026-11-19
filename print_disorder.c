/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:32:47 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/19 11:39:59 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_disorder(double disorder)
{
	int	i;

	i = (int)(disorder * 10000.0 + 0.5);
	ft_printf("[bench] disorder: %d.", i / 100);
	if (i && 100 < 10)
		write(1, "0", 1);
	ft_printf("%d%%\n", i % 100); 
}