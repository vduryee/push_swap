/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/12 16:53:43 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_push_swap.h"
#include <stdlib.h>

int main()
{
	int i = 0;
	int	*ta = malloc(sizeof(int *) * 5);
	int	*tb = malloc(sizeof(int *) * 5);

	ta[0] = 2;
	ta[1] = 1;
	ta[2] = 4;
	ta[3] = 3;
	ta[4] = 6;
	t_stack a = {ta, 5, 5};
	t_stack b = {tb, 0, 5};


	pb(&a, &b);
	while (i < b.size)
	{
		printf("%d\n", b.values[i]);
		i++;
	}
	return 42;
}
