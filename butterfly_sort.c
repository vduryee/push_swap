/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:55:04 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/20 14:16:33 by alegaspa         ###   ########.fr       */
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
	mid = (box * range) - (range / 2);
	if (a->capacity > 500)
		range = 1.5 * ft_sqrt(a->capacity);
	while (i < (box * range) && a->size != 0)
	{
		while (a->values[a->size - 1] > (box * range) - 1)
			rotate(a, count, 'a');
		push(a, b, count, 'b');
		if (b->values[b->size - 1] < mid && b->size > 1)
			rotate(b, count, 'b');
		i++;
	}
}

void	butterfly_push_a(t_stack *a, t_stack *b, t_counter *count, int box)
{
	int	i;
	int	range;
	int	p;
	int	max;
	
	p = 0;
	max = 0;
	range = 10;
	i = b->size;
	while (i > (box - 1) * range)
	{
		if (b->values[b->size - 1] == i - 1)
		{
			push(b, a, count, 'a');
			i--;
			if (p == 1)
			{
				i--;
				p = 0;
				swap(a, count, 'a');
			}
		}
		else if (b->values[b->size - 1] == i - 2 && p == 0)
		{
			push(b, a, count, 'a');
			p = 1;
		}
		else if (b->values[b->size - 2] == i - 1)
			swap(b, count, 'b');
		else if (b->size > 5 && (b->values[b->size - 3] == i - 1 || b->values[b->size - 4] == i - 1 || b->values[b->size - 5] == i - 1))
			rotate(b, count, 'b');
		else if (b->size > 0)
			rev_rotate(b, count, 'b');
	//	ft_printf("%d\n\n", b->size);
		ft_printf("%d\n\n", b->values[b->size - 1]);
		ft_printf("%d\n\n", p);
	//	ft_printf("%d\n\n", i);
		
	}
}

void	butterfly_sort(t_stack *a, t_stack *b, t_counter *count)
{
	int	i;

	i = 0;
	while (i < 51)
	{
		butterfly_push_b(a, b, count, i);
		i++;
	}
	while (i > 0)
	{
		butterfly_push_a(a, b, count, i);
		i--;
	}
}
