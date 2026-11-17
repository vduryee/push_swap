/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:55:04 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/17 10:58:14 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i != nb) && i < nb)
		i++;
	return (i);
}

void	butterfly_push(t_stack *a, t_stack *b, t_counter *count)
{
	size_t	size_box;
//	size_t	n_box;
	size_t	box;
	size_t	i;
	size_t	mid;

	box = 1;
	size_box = 1.5 * (ft_sqrt((int)a->capacity));
//	n_box = (a->capacity / size_box) + 1;
	while (a->size > 0)
	{
		mid = ((box * size_box) + (box * size_box) - size_box - 1)/
			2;
		i = size_box;
		while ((box * size_box) - i < (box * size_box))
		{
			while (a->values[a->size - 1] > (int)(size_box - 1))
				rev_rotate(a, count, 'a');
			push(a, b, count, 'b');
			if (b->values[b->size - 1] < (int)mid && b->size > 2)
				rotate(b, count, 'b');
			i--;
		}
		box++;
	}
}
