/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:55:04 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/17 22:11:57 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i != nb) && i < nb)
		i++;
	return (i);
}

void	butterfly_push_b(t_stack *a, t_stack *b, t_counter *count, int box)
{
	static int	i = 0;
	int	range;
	int	mid;

	range = 10;
	mid = ((box * range) - 1) / 2;
	if (a->capacity > 500)
		range = 1.5 * ft_sqrt(a->capacity);
	while (i < (box * range) - 1 && a->size != 0)
	{
		while (a->values[a->size - 1] != i)
			rev_rotate(a, count, 'a');
		push(a, b, count, 'b');
		if (b->values[b->size - 1] < mid && b->size > 2)
			rev_rotate(b, count, 'b');
		i++;
	}
}

//void	butterfly_push_a
void	butterfly_sort(t_stack *a, t_stack *b, t_counter *count)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		butterfly_push_b(a, b, count, i);
		i++;
	}
}
